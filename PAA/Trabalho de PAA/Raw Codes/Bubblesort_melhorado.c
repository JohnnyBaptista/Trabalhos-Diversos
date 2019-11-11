#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define max 1000

void bubblesort(int x, int y, int vetor[max]);

void bubblesort(int x, int y, int vetor[max]){
  int aux = 0;

  int troca = 1;
	
	for (x = 0; (x < max-1) && troca; x++)
	{
		troca = 0;
			for(y= 0; y < max-x-1; y++)
			{
				if (vetor[y] > vetor[y+1])
					{
						troca = 1;
						aux = vetor[y];
						vetor[y] = vetor[y+1];
						vetor[y+1] = aux;
					}
			}
	}
  	
	return;
}



int main (void){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i,j,v[max],x=0,y=0;
	float total_time,start,end;
	
	srand(time(NULL));

	for(i=0; i<max; i++)
		v[i]= rand()%10000;
	
	printf("\n *Valores sendo gerados automaticamente*\n");
	printf("\n              *Bubble Sort*\n");
	
	start = clock();
	bubblesort(x,y,v);
	end = clock();
	
	/*printf("Vetor organizado:\n");
	for(j=0; j<max; j++)
		printf("%d\n",v[j]);*/
	
	total_time = (float)(end-start)/CLK_TCK;
	
	printf("\n->Tempo de execução do algoritmo Método Bolha: %f\n", total_time);
	
}
