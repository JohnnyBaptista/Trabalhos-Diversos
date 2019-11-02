#ifndef EDITOR_H
#define EDITOR_H

typedef struct Linha_l * Linha;
typedef struct Texto_t * Texto;
typedef Texto Cursor;

Linha linha_novo(Linha ant, Texto texto);
Texto texto_novo(char caractere);
void texto_apagar(Texto texto);
char * texto_parastring(Texto texto,Cursor cursor);
Texto texto_abrir(char * const arquivo, Linha linha);
void texto_salvar(Texto texto,char * nome_do_arquivo);
Cursor texto_inserirchar(Texto texto,Cursor cursor,char caractere, Linha linha);
void texto_deletarchar(Texto * texto,Cursor * cursor);
void texto_bdeletarchar(Texto * texto,Cursor * cursor);
void texto_movercursor(Texto texto,Cursor * cursor,long int num);
void texto_limpar();
int procurar(char * palavra, char texto[]);
void como_usar(void);
void menu(char *nome_arquivo);

#endif