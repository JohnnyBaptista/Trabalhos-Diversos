#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define JUMP printf("\n\n")

int i, j, k;

int main(){
	setlocale(LC_ALL, "Portuguese");
	int larg1, larg2, alt1, alt2; // Declaração de variaveis de linhas e colunas
	float mult, aux;

	system("cls");
	// Recebe a informação do usuário de lin X col da matriz 1 e 2
	printf("Entre com a largura(qnt. colunas) da Matriz 1 \n"); scanf("%d", &larg1);
	printf("Entre com a altura(qnt. linhas) da Matriz 1 \n"); scanf("%d", &alt1);
	printf("Entre com a largura(qnt. colunas) da Matriz 2 \n"); scanf("%d", &larg2);
	printf("Entre com a altura(qnt. linhas) da Matriz 2 \n"); scanf("%d", &alt2);
	// Cria matrizes 1 2 e 3 de acordo com o valor de entrada
	float matriz1[alt1][larg1];
	float matriz2[alt2][larg2];
	float matriz3[alt1][larg2];

	// Verificação de condição de possibilidade de multiplicação de matrizes
	if(larg1 != alt2){
		system("cls");
		printf("Não é possível fazer a multiplicação entre essas matrizes\n");
		printf("O número de colunas da Matriz 1 é diferente do número de linhas da Matriz 2 \n");
		system("pause");
	}
	else{
		system("cls");
		//recebe a matriz 1
		for(i = 0; i < alt1; i++){
			for(j = 0; j < larg1; j++){
				printf("Matriz 1[%d][%d] = ", i+1, j+1);
				scanf("%f", &aux);
				matriz1[i][j] = aux; 
			}
		}
		JUMP;
		//recebe a matriz 2
		for(i = 0; i < alt2; i++){
			for(j = 0; j < larg2; j++){
				printf("Matriz 2[%d][%d] = ", i+1, j+1);
				scanf("%f", &aux);
				matriz2[i][j] = aux; 
			}
		}

		//imprime matrizes atuais
		printf("MATRIZES ATUAIS\n");
		printf("A: \n");
		for(i = 0; i < alt1; i++){
			for(j = 0; j < larg1; j++){
				printf("[%.2f]", matriz1[i][j]);
			}
			printf("\n");
		}
		printf("\nB: \n");
		for(i = 0; i < alt2; i++){
			for(j = 0; j < larg2; j++){
				printf("[%.2f]", matriz2[i][j]);
			}
			printf("\n");
		}

		//multiplicação das matrizes 1 e 2 gerando a 3
		//larg1 x alt2 = linha da matriz1 vezes a coluna da matriz2

		for(i = 0; i < alt1; i++) 
			for(j = 0; j < larg2; j++){
				mult = 0;
				for(k = 0; k < alt1; k++) 
					mult += matriz1[i][k] * matriz2[k][j];
				matriz3[i][j] = mult;
			}

		printf("MATRIZ C: \n");
		for(i = 0; i < alt1; i++){
			for(j = 0; j < larg2; j++){
				printf("[%.2f]", matriz3[i][j]);
			}
			printf("\n");
		}

		system("pause");
		system("cls");

	}

	return 0;
}