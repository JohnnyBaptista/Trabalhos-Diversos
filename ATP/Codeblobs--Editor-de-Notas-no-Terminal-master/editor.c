#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <ctype.h>
#include <string.h>
#include "editor.h"

//====================================================================

typedef struct Texto_t{
	struct Texto_t * ant;
	char letra;
	struct Texto_t * pro;
} * Texto;

typedef Texto Cursor;

typedef struct Linha_l {
	struct Texto_t * elem;
	struct Linha_l * antL;
	struct Linha_l * proxL;
} * Linha;

//====================================================================

static char * * strings = NULL;
static unsigned int n_strings = 0;

//====================================================================

Linha linha_novo(Linha ant, Texto texto) { //Cria um novo nó de linha
	Linha linha = malloc(sizeof(struct Linha_l));
	linha->antL = ant;
	linha->elem = texto;
	linha->proxL = NULL;
	return linha;
} //linha_novo

//====================================================================

Texto texto_novo(char caractere){ //Cria um novo nó da string dinâmica
	Texto lista = malloc(sizeof(struct Texto_t));
	if(lista == NULL){
		return NULL;
	}
	lista->ant = NULL;
	lista->letra = caractere;
	lista->pro = NULL;
	return lista;
} //texto_novo

//====================================================================

void texto_apagar(Texto texto){ //Apaga nó de caracter anterior
	for(;texto->ant != NULL;texto = texto->ant);
	texto = texto->pro;
	for(;texto->pro != NULL;texto = texto->pro){
		free(texto->ant);
	}
	free(texto->ant);
	free(texto);
} //texto_apagar

//====================================================================

char * texto_parastring(Texto texto,Cursor cursor){ //Converte da ED p/ string, para printar a estrutura na tela
	if(texto == NULL){
		return NULL;
	}
	while(texto->pro != NULL){
		texto = texto->pro;
	}
	unsigned int tamanho;
	unsigned int cursorpos = 0;
	for(tamanho = 1;texto->ant != NULL;++tamanho,texto = texto->ant);
	Texto i;
	if(cursor != NULL){
		for(i = texto;i != cursor;i = i->pro);
		for(;i != NULL;++cursorpos){
			i = i->pro;
		}
	}
	tamanho += cursorpos + 1;
	char * string = calloc(tamanho,sizeof(char));
	unsigned int pos = 0;
	for(i = texto;i != NULL;i = i->pro){
		string[pos] = i->letra;
		++pos;
	}
	if(cursor != NULL){
		unsigned int j;
		for(i = texto,j = 0;j < cursorpos;++j,i = i->pro){
			string[pos] = '\b';
			++pos;
		}
	}
	string[pos] = '\0';
	strings = realloc(strings,sizeof(char * *)*n_strings);
	strings[n_strings] = string;
	++n_strings;
	return string;
} //texto_parastring

//====================================================================

Texto texto_abrir(char * const arquivo,Linha linha){ //Abre o arquivo de texto e coloca os dados na estrutura
	unsigned int i;
	for(i = 0;arquivo[i] != '\0';++i){
		if(arquivo[i] == '\n'){
			arquivo[i] = '\0';
			break;
		}
	}
	FILE * arq = fopen(arquivo,"r");
	Texto texto = malloc(sizeof(struct Texto_t));
	linha = linha_novo(NULL, texto);
	texto->ant = NULL;
	texto->pro = NULL;
	if(arq == NULL){
		return NULL;
	}
	while(!feof(arq)){
		texto->letra = fgetc(arq);
		if(texto->letra == '\n') {
			linha->proxL = linha_novo(linha, texto->pro);
			linha = linha->proxL;
		}
		texto->pro = malloc(sizeof(struct Texto_t));
		texto->pro->ant = texto;
		texto->pro->pro = NULL;
		texto = texto->pro;	
	}
	texto = texto->ant;
	free(texto->pro);//apaga o caractere alocado a mais
	texto = texto->ant;
	free(texto->pro);//apaga o '\n' do final do arquivo
	texto = texto->ant;
	free(texto->pro);//apaga o EOF de texto
	texto->pro = NULL;
	fclose(arq);
	return texto;
} //texto_abrir

//====================================================================

void texto_salvar(Texto texto,char * nome_do_arquivo){ //Salva os dados da ED no arquivo
	for(;texto->ant != NULL;texto = texto->ant);
	unsigned int i;
	for(i = 0;nome_do_arquivo[i] != '\0';++i){
		if(nome_do_arquivo[i] == '\n'){
			nome_do_arquivo[i] = '\0';
			break;
		}
	}
	FILE * arquivo = fopen(nome_do_arquivo,"w");
	if(arquivo == NULL){
		return;
	}
	for(;texto != NULL;texto = texto->pro){
		fputc(texto->letra,arquivo);
	}
	fputc('\n',arquivo);
	fclose(arquivo);
} //texto_salvar

//====================================================================

Cursor texto_inserirchar(Texto texto,Cursor cursor,char caractere, Linha linha){ //Insere novo nó de caracter e atualiza cursor
	if(texto == NULL){
		return NULL;
	}
	if(cursor == NULL){
		while(texto->pro != NULL){
			texto = texto->pro;
		}
	}
	Texto novo = malloc(sizeof(struct Texto_t));
	novo->letra = caractere;
	if(cursor != NULL){
		novo->ant = cursor->ant;
		novo->pro = cursor;
		if(cursor->ant != NULL){
			cursor->ant->pro = novo;
		}
		cursor->ant = novo;
	}else{
		novo->ant = texto;
		novo->pro = NULL;
		texto->pro = novo;
	}
	if(caractere == '\n') {
		linha->proxL = linha_novo(linha, cursor);
		linha = linha->proxL;
		printw("\n");
	}
	return novo;
} //texto_inserirchar

//====================================================================

void texto_deletarchar(Texto * texto,Cursor * cursor){ //Deleta prox caracter
	if((*cursor) == NULL){
		return;
	}
	if(((*cursor)->ant == NULL)&&((*cursor)->pro == NULL)){
		return;
	}
	if((*cursor)->pro != NULL){
		Texto aux = *cursor;
		if(texto == cursor){
			*texto = (*texto)->pro;
		}
		*cursor = (*cursor)->pro;
		if((*cursor)->ant->ant != NULL){
			(*cursor)->ant->ant->pro = *cursor;
		}
		(*cursor)->ant = (*cursor)->ant->ant;
		free(aux);
		return;
	}else{
		if((*cursor)->ant != NULL){
			if((*cursor) == (*texto)){
				(*texto) = (*texto)->ant;
			}
			(*cursor) = (*cursor)->ant;
			free((*cursor)->pro);
			(*cursor)->pro = NULL;
			(*cursor) = NULL;
			return;
		}else{
			(*cursor)->letra = ' ';
			return;
		}
	}
} //texto_deletarchar

//====================================================================

void texto_movercursor(Texto texto,Cursor * cursor,long int num){ //Move cursor
	if(texto == NULL){
		return;
	}
	if(num == 0){
		return;
	}
	if(num > 0){
		if((*cursor) == NULL){
			return;
		}else{
			while((num)&&((*cursor) != NULL)){
				*cursor = (*cursor)->pro;
				--num;
			}
			return;
		}
	}else{
		if((*cursor) == NULL){
			(*cursor) = texto;
			while((*cursor)->pro != NULL){
				*cursor = (*cursor)->pro;
			}
			++num;
		}
		if((*cursor)->ant == NULL){
			return;
		}
		while((num)&&((*cursor)->ant != NULL)){
			*cursor = (*cursor)->ant;
			++num;
		}
		return;
	}
} //texto_movercursor

//====================================================================

void texto_limpar(){ //	Limpa a string
	unsigned int i;
	for(i = 0;i < n_strings;++i){
		free(strings[i]);
	}
	free(strings);
	strings = NULL;
	n_strings = 0;
} //texto_limpar

//====================================================================

int procurar(char * palavra,char * texto){ //Procura palavra na ED
	 
	unsigned int i;
	for(i = 0;palavra[i] != '\0';++i){
		if(palavra[i] == '\n'){
			palavra[i] = '\0';
			break;
		}
	}
	char * delims = " ";
    char * result = NULL;
    result = strtok( texto, delims );
     
    while( result != NULL ) {
        if(strcmp(palavra, result) == 0) {
        	attron(A_BOLD);
            printw("%s ", palavra);
            attroff(A_BOLD);
            refresh();
            result = strtok( NULL, delims );
        } else {
            printw("%s ", result);
            refresh();
            result = strtok( NULL, delims );
        }
    }
    getch();
    printw ("\n");
} //procurar

//====================================================================

void como_usar(void) { //Informações quanto ao uso
	printf( "=================================================\n"
		"Ins:   Procurar palavra \n"
	    "Enter: Salvar \n"
		"Esc:   Salvar e fechar \n"
		"F2:    Ajuda \n"
		"\n"
	   	"Nome autores: João Pedro da Silva Baptista\n"
		"              Vinícius Vedovotto\n"            
		"Trabalho de ED I - Professor Ronaldo\n"
		"Versão v1.0\n"
		"=================================================\n\n");
} //como_usar

//====================================================================

void menu(char *nome_arquivo) { //Menu de opções
	char op;
	printf("n - Deseja criar novo arquivo de texto \n"
           "a - Abrir existente \n"
           "c - Cancelar \n"
           ">");
  	scanf("%c", &op);
  	op = toupper(op);
 	if(op == 'A') {
   		printf("Qual o nome do arquivo? [sem espaços]\n");
    	scanf("%s", nome_arquivo);
  	} else if(op == 'N') {
    	printf("Qual será o nome do seu arquivo? [sem espaços]\n");
	  	scanf("%s", nome_arquivo);
    	FILE* f;	
	 	if( (f=fopen(nome_arquivo, "w+r")) == NULL) { //Cria novo arquivo
      		printf("ERRO na criação do arquivo %s!!! \n", nome_arquivo);
      		exit(1); 
    	}
	  	fputs("Escreva aqui ", f);
    	fclose(f);
 	} else if(op == 'C') exit(EXIT_SUCCESS); //Cancela processo
    else printf("Entrada inválida!\n");
} //menu