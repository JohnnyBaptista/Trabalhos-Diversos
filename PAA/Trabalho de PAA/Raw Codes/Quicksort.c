#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define max 1000

void Quick(int vetor[max], int inicio, int fim);

void Quick(int vetor[max], int inicio, int fim)
{
	
	int pivo, aux, i, j, meio;
	
	i = inicio;
	j = fim;
	
	meio = (int) ((i + j) / 2);
	pivo = vetor[meio];
	
	do
	{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
		
		if(i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	} while(j > i);
	
	if(inicio < j) Quick(vetor, inicio, j);
	if(i < fim) Quick(vetor, i, fim);	

}




int main (void){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i,j,v[max];
	float total_time,start,end;
	
	srand(time(NULL));

	for(i=0; i<max; i++)
		v[i]= rand()%10000;
	
	printf("\n *Valores sendo gerados automaticamente*\n");
	printf("\n              *Quicksort*\n");
	
	start = clock();
	Quick(v, 0, max);
	end = clock();
	
	/*printf("Vetor organizado:\n");
	for(j=0; j<max; j++)
		printf("%d\n",v[j]);*/
	
	total_time = (float)(end-start)/CLK_TCK;
	
	printf("\n->Tempo de execução do algoritmo Quicksort: %f\n", total_time);
	
}
