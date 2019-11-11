#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define max 1000

int main (void){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i,v[max];
	float total_time,start,end;
	
	srand(time(NULL));

	for(i=0; i<max; i++)
		v[i]= rand()%10000;
	
	printf("\n *Valores gerados automaticamente*\n");
	
	start = clock();
	for(i; i>0; i--)
		printf("%d\n",v[i]);
	end = clock();
	
	total_time = (float)(end-start)/CLK_TCK;
	
	printf("\nTempo de execução: %f", total_time);
	
}
