#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define max 1000

void insertionSort(int *vetor);

void insertionSort(int *vetor)
{
 int i, j, k;
  
 	for(i = 1; i < max; i++)
 	{
  		k = vetor[i];
  			for(j = i-1; j >= 0 && k < vetor[j]; j--)
  			{
   				vetor[j+1] = vetor[j];
  			}
  		vetor[j+1] = k;
 	}
}

int main (void){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i,x,v[max];
	float total_time,start,end;
	
	srand(time(NULL));

	for(i=0; i<max; i++)
		v[i]= rand()%10000;
	
	printf("\n *Valores sendo gerados automaticamente*\n");
	printf("\n              *Insertion Sort*\n");
	
	start = clock();
	insertionSort(v);
	end = clock();
	
	/*printf("Vetor organizado:\n");
	for(x=0; x<max; x++)
		printf("%d\n",v[x]);*/
	
	total_time = (float)(end-start)/CLK_TCK;
	
	printf("\n->Tempo de execução do algoritmo Insertion Sort: %f\n", total_time);
	
}
