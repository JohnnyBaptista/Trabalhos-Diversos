#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#include <locale.h>

#define max 75000

FILE *f;
FILE *f1;
FILE *f2;


int op,op1;

void Gerar_Array(int vetor[max]);
void Vetor_Crescente(int vetor[max]);
void Vetor_Decrescente(int vetor[max]);

void Registrar_a_execucao(float c[max],int i,int tipo,int ordem);
void mostrar_o_vetor(int vetor[max]);

void swap(int *xp, int *yp);

void insertionSort(int *vetor);
void bubblesort_normal(int vetor[max]);
void bubblesort(int vetor[max]);
void Quick(int vetor[max], int inicio, int fim);
void heap_sort(int *vetor);
void merge(int vetor[max], int comeco, int meio, int fim);
void mergeSort(int vetor[max], int comeco, int fim);
void selectionSort(int vetor[max]);

