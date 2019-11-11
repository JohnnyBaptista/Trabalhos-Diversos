//
// Created by ratob on 20/06/2019.
//

#include "headers/puzzle_stack.h"
// Info do puzzle
const char *puzzle1_intro = 	"Ao chegar em uma passagem, voce observa o que parece ser uma estatueta\n"
                               "em cima de um altar de pedra, este esta cheio de sangue e contem velas\n"
                               ", duas delas no caso, em cada lado da estatueta. Se voce podesse desc-\n"
                               "rever a estatueta, acreditaria ser um tipo de criatura com forma huma-\n"
                               "noide com asas de morcego e sua cabeça, ela por si, parecia que a pele\n"
                               "de sua composicao era fina, permitindo visualiar o cranio, mas isto eh\n"
                               "apenas algo do qual sua mente tentou interpretar a visualizar tal ped-\n"
                               "aco de ceramica vil, o relevo de tal coisa eh escuro como a noite.\n\n";

const char *puzzle1 = 	"Apos observar o altar, voce nota que ao seu lado tem escrituras na parede\n"
                         "e nelas estao escritos 4 frases...\n\n"
                         " \"..Primeiro os ventos frios do oeste sopraram sobre todo o reino\"\n"
                         " \"..Segundo as plantacoes morreram pelo sangue de seus proprios camponeses\"\n"
                         " \"..Terceiro os lacaios do abismo surgirao, trazendo o caos e a desordem\"\n"
                         " \"..Por fim, nosso lorde retornara e #%@#%!@#@#¨@$¨&#%#%##$@#%@#¨#$¨#¨#$%\"\n\n"
                         "\nNessa ultima transricao, a frase torna-se ilegivel...\n"
                         "Em baixo dessas escrituras, 4 amuletos estao organizados em determina-\n"
                         "dos caixotes, e no altar exite um mecanismo para empilhar os amuletos.\n\nO que fazer agora... ?\n\n";

const char *puzzle1_escrituras = "\"..Primeiro os ventos frios do oeste sopraram sobre todo o reino\"\n"
                                 "\"..Segundo as plantacoes morreram pelo sangue de seus proprios camponeses\"\n"
                                 "\"..Terceiro os lacaios do abismo surgirao, trazendo o caos e a desordem\"\n"
                                 "\"..Por fim, nosso lorde retornara e #%@#%!@#@#¨@$¨&#%#%##$@#%@#¨#$¨#¨#$%\"\n\n"
                                 "\nNessa ultima transricao, a frase torna-se ilegivel...\n";

const char *puzzle1_vento = 	 "\nO amuleto tem cravatura de um tipo de ser vivo assoprando as nuvens em direcao\n"
                                "ao leste.\n"
                                "\nEste eh o:\n Amuleto do Vento\n\n";

const char *puzzle1_criaturas =  "\n\"Criatura\" seria o nome mais amigavel dado ao inominavel que esta cravado nes-\n"
                                 "se amuleto...\n"
                                 "\nEste eh o:\n Amuleto das Criaturas\n\n";

const char *puzzle1_camponeses=  "\nNa gravura desse amuleto, um campones sofre com um tipo de doenca, esta parece vir\n"
                                 "das plantacoes...\n"
                                 "\nEste eh o:\n Amuleto do Campones\n\n";

const char *puzzle1_monstro = 	 "\n\"Coisa\",\"criatura\",\"monstro\", nao importa qual adjetivo voce use,ele nao eh\n"
                                  "o suficiente para descrever \"esse(a)\" fera, seria isso o lord ao qual a escrit-\n"
                                  "ura se refere ?\n"
                                  "\nEste eh o:\n Amuleto do Monstro\n\n";

void clrscr(){ // Funcao para limpa a tela
    system("cls");
}

int puzzle_stacks() {

    start_stack_main(); // Iniciando a pilha
	// Variaveis a serem usadas para o puzzle
	int ordem_dos_amuletos,aux,contador;
	int exit = 0;
    int i = 1;
    int j = 0;
    int resolveu = 0;
    int desistiu = 0;
    int op = 0;
    int resultado = 0;
    int analisado2 = 0;
    int a1,a2,a3,a4,analisado;
    
    ordem_dos_amuletos = aux = contador = 0;
    a1 = a2 = a3 = a4 = 0;
    analisado = 1;
    
    char tipo_amuleto[35];
    char choice[35];
    
    system("cls");
    printf("%s", puzzle1_intro);
	printf("%s\n", puzzle1);
	system("pause");
	
	while(resolveu != 1){
		system("cls");
		j = 0;
		printf("Voce sabe que precisa empilhar os amuletos...\n\n");
		printf("	*******************************\n");
		printf("	* 0 - Desistir do puzzle.     *\n");
		printf("	* 1 - Resolver o puzzle.      *\n");
		printf("	* 2 - Observar as escrituras. *\n");
		printf("	* 3 - Observar os amuletos.   *\n");
		printf("	*******************************\n");
		printf(">>: ");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				resolveu = 1;
				desistiu = 1;
				printf("\n Voce desistiu do puzzle, e logo em seguide voce se questiona o que fazer agora...\n");
				break;
			case 1:
				system("cls");
				printf("		**Escreva sair, para voltar as opcoes do puzzle.**\n");
				printf("Digite o nome do amuleto a ser colocado\n");
				fflush(stdin);
				while(j < 4){
					printf(">>:");
					gets(tipo_amuleto);
					
					if(strcasecmp("Amuleto do Campones",tipo_amuleto) == 0){
						//printf("\nEntro\n");
						push_stack_main(2);
						j++;
					}
					else if(strcasecmp("Amuleto do Vento",tipo_amuleto) == 0){
						//printf("\nEntro\n");
						push_stack_main(1);
						j++;
					}
					else if(strcasecmp("Amuleto das Criaturas",tipo_amuleto) == 0){
						//printf("\nEntro\n");
						push_stack_main(3);
						j++;
					}
					else if(strcasecmp("Amuleto do Monstro",tipo_amuleto) == 0){
						//printf("\nEntro\n");
						push_stack_main(4);
						j++;
					}
					else if(strcasecmp("sair",tipo_amuleto) == 0){
						j = 5;
						exit = 1;
					}
					else{
						printf("\n Voce deve digitar o nome de um amuleto valido!\n\n");
					}
				
				}
				
				ordem_dos_amuletos = 4;
				
				if(exit != 1){
					while(contador < 4){
						aux = stack_get_main(resultado);
						if( aux == ordem_dos_amuletos){
							resultado++;
						}
						ordem_dos_amuletos--;
						contador++;
					}
				}
				
				if ( resultado == 4) {
 					printf("\nVoce resolveu o puzzle!\n");
 					resolveu = 1;
 					system("pause");
				}
				
				else{
					printf("\nAlgo deu errado na resolucao do puzzle...\n");
					system("pause");
					destroy_stack_main();
					start_stack_main();	
				}
				
				break;
			case 2:
				system("cls");
				printf("Voce volta a analisar as escrituras...\n\n");
				printf("%s\n", puzzle1_escrituras);
				system("pause");
				break;
			case 3:
				strcpy(choice, "a");
				system("cls");
				fflush(stdin);
				printf("		**Escreva sair, para voltar as opcoes do puzzle.**\n");
				printf("Voce comeca a analisar os amuletos.\n");
				
				if(a1 == 1){
					printf("Amuleto 1 revela ser o: Amuleto do Vento\n");
				}
				
				else{
					printf("Amuleto 1\n");
				}
					
				if(a3 == 1){
					printf("Amuleto 3 revela ser o: Amuleto das Criaturas\n");
				}
				
				else{
					printf("Amuleto 3\n");
				}
	
				if(a2 == 1){
					printf("Amuleto 2 revela ser o: Amuleto do Campones\n");
				}
				
				else{
					printf("Amuleto 2\n");
				}

				if(a4 == 1){
					printf("Amuleto 4 revela ser o: Amuleto do Monstro\n");
				}
					
				else {
					printf("Amuleto 4\n");
				}
					
				
				printf("\nVoce vai pegar qual dos amuletos para ser analisado ?\n >:");
				gets(choice);
				fflush(stdin);
				
				if(analisado <= 4){
					if(strcasecmp("Amuleto 1",choice) == 0){
						printf("%s\n", puzzle1_vento);
						a1 = 1;
						analisado++;
					}
				
					else if(strcasecmp("Amuleto 2",choice) == 0){
						printf("%s\n", puzzle1_camponeses);
						a2 = 1;
						analisado++;
					}
				
					else if(strcasecmp("Amuleto 3",choice) == 0){
						printf("%s\n", puzzle1_criaturas);
						a3 = 1;
						analisado++;
					}
				
					else if(strcasecmp("Amuleto 4",choice) == 0){
						printf("%s\n", puzzle1_monstro);
						a4 = 1;
						analisado++;
					}
				}
				
				else if (analisado == 4){
					if(strcasecmp("Amuleto do Vento",choice) == 0){
						printf("%s", puzzle1_vento);
						a1 = 1;
					}
				
					else if(strcasecmp("Amuleto do Campones",choice) == 0){
						printf("%s", puzzle1_camponeses);
						a2 = 1;
					}
				
					else if(strcasecmp("Amuleto das Criaturas",choice) == 0){
						printf("%s", puzzle1_criaturas);
						a3 = 1;
					}
				
					else if(strcasecmp("Amuleto do Monstro",choice) == 0){
						printf("%s", puzzle1_monstro);
						a4 = 1;
					}
				}
				
				system("pause");
				break;
			default:
				printf("\nVoce nao entende o que eh para fazer...\n");
				break;
		}
	}
	
	if( desistiu == 1)
		return 0;
	
	else
		return 1;
}

void start_stack_main() { // Inicia a pilha
    top_main = NULL;
    counter_main = 0;
}

int stack_vazia_main() { // Verifica se a pilha ta vazia
    if (top_main == NULL)return 1;

    else return 0;
}

int push_stack_main(int value) { // Empilha um valor
    p_main *novo_node = (p_main *) malloc(sizeof(p_main));

    if (novo_node == NULL) return 0;

    else {
        novo_node->info = value;
        novo_node->next = top_main;

        top_main = novo_node;
        counter_main++;

        return 1;
    }
}

int stack_get_main(int value) { // Retorna um valor da pilha
    value = top_main->info;
    top_main = top_main->next;
    return value;
}

int destroy_stack_main() { // Destroi a pilha
    int aux;
    p_main *temp_main;

    if (stack_vazia_main()) return 0;

    else {
        while (top_main != NULL) {
            temp_main = top_main;
            temp_main->next = NULL;
            top_main = top_main->next;

            free(temp_main);
        }
        counter_main = 0;
        return 1;
    }
}

