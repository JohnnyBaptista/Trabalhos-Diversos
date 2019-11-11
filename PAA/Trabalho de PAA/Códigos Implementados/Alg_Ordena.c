#include "main.h"

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

void bubblesort(int vetor[max]){
  int aux = 0;
  int x,y;
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

void bubblesort_normal(int vetor[max]){
  int aux = 0,j,i;

	for (j = 0; j < max-1; j++)
	{
 		for(i= 0; i < max-j-1; i++)
		{
  			if (vetor[i] > vetor[i+1])
			   {
  					aux = vetor[i];
   					vetor[i] = vetor[i+1];
   					vetor[i+1] = aux;
    			}
	 	}
   }
  		return;
}

void Quick(int vetor[max], int inicio, int fim)
{

	int pivo, aux, i, j, meio;

	i = inicio;
	j = fim;

	meio = (int) ((i + j) / 2);
	pivo = vetor[meio];
	
	/*meio = (int) ((i));
	pivo = vetor[meio];*/

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


void merge(int vetor[max], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
}

void mergeSort(int vetor[max], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void heapsort(int a[max], int n) {

    int i = n / 2, pai, filho, t;
    while (1==1) {

        if (i > 0) {

            i--;
            t = a[i];
        }else{

            n--;
            if (n == 0) return;
            t = a[n];
            a[n] = a[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {

            if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))filho++;

            if (a[filho] > t) {

                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }else{

                break;
            }
        }
        a[pai] = t;
    }
}

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
            }
            vet [j] = value;
        }
    }
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int vetor[max]) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < max-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < max; j++) 
          if (vetor[j] < vetor[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&vetor[min_idx], &vetor[i]); 
    } 
} 
