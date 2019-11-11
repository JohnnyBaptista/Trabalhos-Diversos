#include "main.h"
#include "Prog_Vetor.c"
#include "Alg_Ordena.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int vetor[max],i=0,tipo,ordem;
	float c[max];

	do{
		setlocale(LC_ALL,"");
		int op;
		system("cls");
		printf("** ->Códigos implementados por Juan Cardoso da Silva e Caio Nogueira **\n\n");
		printf("****************************************************\n");
		printf("* Digitar 1 -> Gerar vetor com valores aleatórios  *\n");
		printf("* Digitar 2 -> Gerar vetor com valores crescente   *\n");
		printf("* Digitar 3 -> Gerar vetor com valores decrescente *\n");
		printf("* Digitar 4 -> Métodos de ordenação do vetor       *\n");
		printf("* Digitar 5 -> Registrar o Tempo de execução       *\n");
		printf("* Digitar 6 -> Visualizar o vetor                  *\n");
		printf("****************************************************\n");

		printf("\nDigite a sua opção: ");
		scanf("%d", &op);

	if(op<=6 && op>=1)
	{
		switch(op)
		{
			case 1:
			{
				Gerar_Array(vetor);
				ordem = 0;
				break;
			}
			case 2:
			{
				Vetor_Crescente(vetor);
				ordem = 1;
				break;
			}
			case 3:
			{
				Vetor_Decrescente(vetor);
				ordem = 2;
				break;
			}
			case 4:
			{
				system("cls");
				printf("Escolha o método de organização:\n");

				printf("* Digitar 1 -> Insertion Sort \n");
				printf("* Digitar 2 -> Bubblesort Normal   \n");
				printf("* Digitar 3 -> Bubblesort\n");
				printf("* Digitar 4 -> QuickSort\n");
				printf("* Digitar 5 -> MergeSort\n");
				printf("* Digitar 6 -> HeapSort\n");
				printf("* Digitar 7 -> ShellSort\n");
				printf("* Digitar 8 -> Seleção direta\n");


				printf("\nDigite a sua opção: ");
				scanf("%d", &op1);

				if (op1<=8 && op1>=1)
				{
					switch(op1)
					{
						case 1:{
							float total_time,start,end;
								start = clock();
								insertionSort(vetor);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);

 								c[i]=total_time;
 								i++;
 								tipo = 1;

							break;
						}

						case 2:{
							float total_time,start,end;
								start = clock();
								bubblesort_normal(vetor);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);

								c[i]=total_time;
 								i++;
 								tipo = 2;
							break;
						}

						case 3:{
							float total_time,start,end;
								start = clock();
								bubblesort(vetor);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);

								c[i]=total_time;
								i++;
								tipo = 3;
							break;
						}

						case 4:{
							float total_time,start,end;
								start = clock();
								Quick(vetor, 0, max);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);

								c[i]=total_time;
								i++;
								tipo = 4;
							break;
						}

						case 5:{
							float total_time,start,end;
								start = clock();
								mergeSort(vetor,0,max);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);
								printf("\n** Tempo:%f **\n",total_time);
								c[i]=total_time;
								i++;
								tipo = 5;
							break;
						}

						case 6:{
							float total_time,start,end;
								start = clock();
								heapsort(vetor, max);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);

								c[i]=total_time;
								i++;
								tipo = 6;
							break;
						}

						case 7:{
							float total_time,start,end;
								start = clock();
                                shellSort(vetor, max);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);

								c[i]=total_time;
								i++;
								tipo = 7;
							break;
						}

						case 8:{
							float total_time,start,end;
								start = clock();
                                selectionSort(vetor);
								end = clock();

								total_time = (float)(end-start)/CLK_TCK;

								printf("\n** Execução:%d **\n",i);

								c[i]=total_time;
								i++;
								tipo = 8;
							break;
						}

					}

				}

				else
				{
					system("cls");
					printf("\nA opção digitiada não existe!\n");

				}

				break;
			}
			case 5:
			{
				Registrar_a_execucao(c,i,tipo,ordem);
				break;
			}
			case 6:
			{
				mostrar_o_vetor(vetor);

				break;
			}
		}
	}
	else
	{
		system("cls");
		printf("\nA opção digitiada não existe!\n");
	}
	

		printf("\nAperta qualquer tecla para continuar ou aperte N para sair...\n");
	}while(toupper(getch())!= 'N');


	return 0;
}
