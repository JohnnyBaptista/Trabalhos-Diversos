#include "main.h"

void Gerar_Array(int vetor[max]){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i;
	
	srand(time(NULL));

	for(i=0; i<max; i++)
		vetor[i]= rand()%75000;
	
	printf("\n *Valores gerados automaticamente*\n");
	
	return;
}

void Vetor_Crescente(int vetor[max]){
	
	setlocale(LC_ALL,"Portuguese");
	
	int j;

	for(j=0; j<max; j++)
		vetor[j]= j;
	
	printf("\n *Valores gerados automaticamente*\n");

	return;
}

void Vetor_Decrescente(int vetor[max]){
	
	setlocale(LC_ALL,"Portuguese");
	
	int k,i=75000;

	for(k = 0; k<max; k++){
		vetor[k] = i;
		i = i - 1;
	}
	
	printf("\n *Valores gerados automaticamente*\n");
	
	return;
}

void Registrar_a_execucao(float c[max],int i,int tipo,int ordem){
	int b;
	
	if(tipo == 1){
		
		if(ordem == 0){
			if( (f=fopen("Execução Insertion Sort Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Insertion Sort com vetor de elementos em ordem aleatória [Execução %d]: %f\n", b,c[b]);
			}
		}
		else if(ordem == 1){
			if( (f=fopen("Execução Insertion Sort Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Insertion Sort com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}			
		}
		
		else{
			if( (f=fopen("Execução Insertion Sort Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Insertion Sort com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}			
		}

	}
	
	else if(tipo == 2){
		
		if (ordem == 0){
			if( (f=fopen("Execução Bubblesort normal Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Bubblesort normal com vetor de elementos em ordem aleatória [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else if(ordem == 1){
			if( (f=fopen("Execução Bubblesort normal Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Bubblesort normal com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else{
			if( (f=fopen("Execução Bubblesort normal Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Bubblesort normal com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}
		}
	}
	
	else if(tipo == 3){
		
		if(ordem == 0){
			if( (f=fopen("Execução Bubblesort Melhorado Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Bubblesort Melhorado com vetor de elementos em ordem aleatório [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else if(ordem == 1){
			if( (f=fopen("Execução Bubblesort Melhorado Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Bubblesort Melhorado com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else{
			if( (f=fopen("Execução Bubblesort Melhorado Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Bubblesort Melhorado com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}
		}
	}
	
	else if(tipo == 4){

		if(ordem == 0){
			if( (f=fopen("Execução Quicksort (Pivô=elemento central) Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do QuickSort com vetor de elementos em ordem aleatória [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else if(ordem == 1){
			if( (f=fopen("Execução Quicksort (Pivô=elemento central) Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do QuickSort com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}
		}

		else{
			if( (f=fopen("Execução Quicksort (Pivô=elemento central) Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do QuickSort com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}
		}
	}
	
	else if(tipo == 5){

		if(ordem == 0){
			if( (f=fopen("Execução Mergesort Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do MergeSort com vetor de elementos em ordem aleatória [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else if(ordem == 1){
			if( (f=fopen("Execução Mergesort Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do MergeSort com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}
		}

		else{
			if( (f=fopen("Execução Mergesort Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do MergeSort com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}
		}
	}
	
	else if(tipo == 6){
		
		if(ordem == 0){
			if( (f=fopen("Execução Heapsort Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do HeapSort com vetor de elementos em ordem aleatória [Execução %d]: %f\n", b,c[b]);
			}
		}

		else if(ordem == 1){
			if( (f=fopen("Execução Heapsort Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do HeapSort com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}
		}

		else{
			if( (f=fopen("Execução Heapsort Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do HeapSort com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}
		}
	}
	
	else if(tipo == 7){
		
		if(ordem == 0){
			if( (f=fopen("Execução Shellsort Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do ShellSort com vetor de elementos em ordem aleatória [Execução %d]: %f\n", b,c[b]);
			}
		}

		else if(ordem == 1){
			if( (f=fopen("Execução Shellsort Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do ShellSort com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}
		}

		else{
			if( (f=fopen("Execução Shellsort Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do ShellSort com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}
		}
	}
	
	else{

		if(ordem == 0){
			if( (f=fopen("Execução Seleção Direta Aleatório.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Seleção Direta com vetor de elementos em ordem aleatória [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else if(ordem == 1){
			if( (f=fopen("Execução Seleção Direta Crescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Seleção Direta com vetor de elementos em ordem crescente [Execução %d]: %f\n", b,c[b]);
			}
		}
		
		else{
			if( (f=fopen("Execução Seleção Direta Decrescente.txt", "w+") ) == NULL) {
    			printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", "Execução.txt");
    			exit(1);
			}
			
			for(b=0; b<i; b++){
				fprintf(f, "Tempo de execução do Seleção Direta com vetor de elementos em ordem decrescente [Execução %d]: %f\n", b,c[b]);
			}
		}
	}
	
		fclose(f);
		
		for(b; b<0; b--)
			c[b]=0;	
		
		printf("\n*Tempo de execução registrado*\n");
		
	return;
}

void mostrar_o_vetor(int vetor[max]){
	int a;
	
	for(a=0; a<max; a++)
		printf("%d\n",vetor[a]);
		
	return;
}
