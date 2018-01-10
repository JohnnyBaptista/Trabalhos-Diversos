//Determinantes de matrizes 3x3

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define JUMP printf("\n\n")

int i, j, k;

int main(){
	setlocale(LC_ALL, "");
	float matrizDet[3][3];
	float aux, det = 0, diagPrin = 0, diagSec = 0 ;
	system("cls");
	printf("Entre com a matriz de tamanho 3x3: \n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++){
			printf("Matriz[%d][%d] = ", i+1, j+1);
			scanf("%f", &aux);	
			matrizDet[i][j] = aux;
		}

		//determinante
		diagPrin = (matrizDet[0][0]*matrizDet[1][1]*matrizDet[2][2])+(matrizDet[0][1]*matrizDet[1][2]*matrizDet[2][0])+(matrizDet[0][2]*matrizDet[1][0]*matrizDet[2][1]);
		diagSec = (matrizDet[0][2]*matrizDet[1][1]*matrizDet[2][0])+(matrizDet[0][1]*matrizDet[1][0]*matrizDet[2][2])+(matrizDet[0][0]*matrizDet[1][2]*matrizDet[2][1]);
		det = diagPrin - diagSec;
		system("cls");
		printf("Matriz resultante: \n");
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				printf("[%.2f]", matrizDet[i][j]);
			}
			printf("\n");
		}
		printf("Seu determinante é igual a: %.2f \n", det );

	return 0;
}
