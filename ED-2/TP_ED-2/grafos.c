//
// Created by ratob on 09/11/2019.
//


// Importacao de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <dirent.h>

// Importacao de outras funcoes e headers
#include "headers/grafos.h"
#include "headers/helper.h"
#include "headers/algoritmos_de_busca.h"
#include "headers/estruturas.h"
#include "headers/mini_controller.h"

//Variaveis globais em grafo.c
FILE *f1, *f2;                           // Variaveis para criacao de arquivos, f1 para leitura, f2 para escrita.
char file_name[50];                      // Variavel utilizada para dar nome ao arquivo de texto criado.
char __function_flow__[7500];            // Variavel para marcar o fluxo de execucao das funcoes no codigo.
bool debug = false;                       // Variavel para ativar certos printfs no console para verificar tipos de erros, prints,
bool __grafo_foi_lido__ = false;
bool __is_dfs_created__ = false;
bool __is_bfs_created__ = false;

aux_ma *aux2_matriz;

//struct info__matriz *grafo_node;
//struct matriz *grafo_matriz_node;

int endsWithSuffix (const char *s, const char *suffix) { // Compra os sufixo do nome do arquivo com a o sufixo dado
    int sLength = strlen(s);
    int suffixLength = strlen(suffix);

    return (sLength >= suffixLength) &&
           (strcmp(s + (sLength-suffixLength), suffix) == 0);
}

// Realiza a leitura de uma matriz serealizada em um arquivo .mt
void ler_matriz(struct matriz *grafo_matriz_node){
    strcat(__function_flow__,"       |--> ler_matriz(struct matriz *grafo_matriz_node) - Onde a matriz eh escrita em um arquivo do tipo .mt .\n");

    int i = 0;
    int j = 0;
    int count = 0;

    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(".");

    printf("Function atual: ler_matriz();\n");
    printf("      **Arquivos de txt no mesmo diretorio**\n");
    printf(" >:Encontrados:\n\n");
    while ( ( lsdir = readdir(dir) ) != NULL ) {
        if(endsWithSuffix (lsdir->d_name,".mt")){
            printf ("%s\n", lsdir->d_name);
        }
    }
    printf("\nDigite o  nome do arquivo do tipo matriz de adjacencia a ser aberto: ");
    scanf("%s", file_name);

    printf("\n");

    if (!endsWithSuffix (file_name,".mt")) {
        printf("Erro - \"%s\" parece nao ser um arquivo mt valido...\n", file_name);
        fclose(f1);
        pause();
    } else {
        if((f1 = fopen(file_name,"r+"))!= NULL){
            fread(grafo_matriz_node, sizeof(struct matriz),1,f1);

            printf("Arquivo lido.\n\n");

            for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                for(j = 0; j < grafo_matriz_node->tamanho; j++) {
                    printf("%d ",grafo_matriz_node->m[i][j]);
                    count++;
                    if(count == grafo_matriz_node->tamanho){
                        printf("\n");
                        count = 0;
                    }
                }
            }

            fclose(f1);

            pause();


        } else{
            printf("\n		-> **erro, nao foi possivel abrir o arquivo .mt ...\n\n");
            fclose(f1);

            pause();


        }
    }
}

// Realiza a escrita da matriz em um arquivo .mt
void escrever_matriz(struct matriz *grafo_matriz_node){
    int i = 0;

    strcat(__function_flow__,"       |--> escrever_matriz(struct matriz *grafo_matriz_node) - Onde a matriz eh lida de um arquivo do tipo .mt .\n");

    printf("Function atual: escrever_matriz();\n");
    printf("\nEscrevendo uma matriz de  em um arquivo...\n");
    printf("Digite o nome do arquivo!\n>: ");
    scanf("%s",file_name);

    if((f1 = fopen(file_name,"w+"))!= NULL){
        fwrite(grafo_matriz_node, sizeof(struct matriz),1,f1);

        printf("Arquivo criado.\n");
        fclose(f1);

        pause();

    } else{
        printf("\n		-> **erro, nao foi possivel criar o arquivo .mt ...\n\n");
        fclose(f1);

        pause();
    }

}

// Verifica as propriedades do grafo.
void verificar_props(struct matriz *grafo_matriz_node) {
    /*int i = 0;
    int j = 0;

    float total_n = 0;
    float total_m = 0;

    float conta_n = 0;
    float proximidade = 0;

    grafo_matriz_node->numero_vertices = grafo_matriz_node->tamanho;
    grafo_matriz_node->numero_arestas = 0;

    for(i = 0; i < grafo_matriz_node->tamanho; i++) {
        for(j = 0; j < grafo_matriz_node->tamanho; j++) {
            if(grafo_matriz_node->m[i][j] == 1){
                grafo_matriz_node->numero_arestas = grafo_matriz_node->numero_arestas + 1;

                if(debug == true)
                    printf("%d\n",grafo_matriz_node->numero_arestas);
            }
        }
    }

    printf("\n");

    if(grafo_matriz_node->tipo == 0){
        total_m = (float)(grafo_matriz_node->numero_arestas);
        total_n = (float)(grafo_matriz_node->numero_vertices);
        conta_n = (total_n * (total_n - 1.0) / 2.0);

        proximidade = total_m - conta_n;

        if(proximidade < 0) {
            proximidade = proximidade * (-1.0);
        }

        if(debug == true) {
            printf("total_m: %f\n",total_m);
            printf("total_n: %f\n",total_n);
            printf("conta_n: %f\n",conta_n);
            printf("proximidade: %f\n",proximidade);
        }

        if(total_m <= conta_n && (total_m >= proximidade || conta_n >= proximidade)) {
            strcat(grafo_matriz_node->classificacao_grafo, "Grafo Esparco\n");
        } else if (total_m <= conta_n && (total_m <= proximidade || conta_n <= proximidade)) {
            strcat(grafo_matriz_node->classificacao_grafo, "Grafo Denso\n");
        }
    } else if(grafo_matriz_node->tipo == 1){
        total_m = (float)(grafo_matriz_node->numero_arestas);
        total_n = (float)(grafo_matriz_node->numero_vertices);
        conta_n = (total_n * (total_n - 1.0));

        proximidade = total_m - conta_n;

        if(proximidade < 0) {
            proximidade = proximidade * (-1.0);
        }

        if(debug == true) {
            printf("total_m: %f\n",total_m);
            printf("total_n: %f\n",total_n);
            printf("conta_n: %f\n",conta_n);
            printf("proximidade: %f\n",proximidade);
        }

        if(total_m <= conta_n && (total_m >= proximidade || conta_n >= proximidade)) {
            strcat(grafo_matriz_node->classificacao_grafo, "->Grafo Esparco\n");
        } else if (total_m <= conta_n && (total_m <= proximidade || conta_n <= proximidade)) {
            strcat(grafo_matriz_node->classificacao_grafo, "->Grafo Denso\n");
        }
    } */

    if(grafo_matriz_node->contem_peso == 1){
        strcat(grafo_matriz_node->classificacao_grafo, "->Grafo Ponderado.\n");
    } else{
        strcat(grafo_matriz_node->classificacao_grafo, "->Sem rotulo.\n");
    }

    printf("\n");

    printf("O tipo do grafo eh:\n%s\n",grafo_matriz_node->classificacao_grafo);

    memset(grafo_matriz_node->classificacao_grafo,0,sizeof(grafo_matriz_node->classificacao_grafo));
    pause();

}

// Realiza a leitura de um grafo a partir de um arquivo de texto.
void ler_grafo(struct info__matriz *grafo_node,struct matriz *grafo_matriz_node){
    strcat(__function_flow__,"       |--> ler_grafo(struct info__matriz *grafo_node,struct matriz *grafo_matriz_node) - Onde o grafo eh lido.\n");

    int i = 0;
    int j = 0;

    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(".");

    printf("Function atual: ler_grafo();\n");
    printf("      **Arquivos de txt no mesmo diretorio**\n");
    printf(" >:Encontrados:\n\n");
    while ( ( lsdir = readdir(dir) ) != NULL ) {
        if(endsWithSuffix (lsdir->d_name,".txt")){
            printf ("%s\n", lsdir->d_name);
        }
    }
    printf("\nDigite o  nome do arquivo de texto a ser aberto: ");
    scanf("%s", file_name);

    printf("\n");

    if (!endsWithSuffix (file_name,".txt")) {
        printf("Erro - \"%s\" parece nao ser um arquivo txt valido...\n", file_name);
        fclose(f1);
        pause();
    } else {
        if((f1 = fopen(file_name, "r+")) != NULL){

            if(__grafo_foi_lido__ == false) {
                printf("\n		->Lendo o txt...\n\n");
                //fscanf(f1, "%c", &flag);
                //fscanf(f1, "%*[^\n]\n", NULL);
                fscanf(f1, "%d", &grafo_node->tipo);
                fscanf(f1, "%d", &grafo_matriz_node->tamanho);

                grafo_matriz_node->tipo = grafo_node->tipo;

                if(grafo_node->tipo == 1) {
                    printf("\ntipo do grafo: digrafo\n");

                    printf("tamanho: %d\n", grafo_matriz_node->tamanho);

                    for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                        for (j = 0; j < grafo_matriz_node->tamanho; j++) {

                            grafo_matriz_node->m[i][j] = 0;
                            grafo_matriz_node->peso[i][j] = 0;
                            grafo_matriz_node->visitado[i] = 0;

                            if(debug){
                                printf("L:%d C:%d V:%d\n",i,j,grafo_matriz_node->m[i][j]);
                            }

                        }
                        grafo_matriz_node->indice[i] = i;
                    }

                    while((fscanf(f1,"%d %d %d",&grafo_node->grafo_saida, &grafo_node->grafo_chegada, &grafo_node->peso)) != EOF){
                        grafo_matriz_node->m[grafo_node->grafo_saida][grafo_node->grafo_chegada] = 1;
                        grafo_matriz_node->peso[grafo_node->grafo_saida][grafo_node->grafo_chegada] = grafo_node->peso;
                        printf("Grafo:%d vertice:%d peso:%d\n",grafo_node->grafo_saida,grafo_node->grafo_chegada, grafo_node->peso);
                    }

                    fclose(f1);

                } else {
                    printf("\ntipo do grafo: grafo\n");

                    printf("tamanho: %d\n", grafo_matriz_node->tamanho);

                    for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                        for (j = 0; j < grafo_matriz_node->tamanho; j++) {

                            grafo_matriz_node->m[i][j] = 0;
                            grafo_matriz_node->peso[i][j] = 0;

                            if(debug){
                                printf("L:%d C:%d V:%d\n",i,j,grafo_matriz_node->m[i][j]);
                            }

                        }
                        grafo_matriz_node->indice[i] = i;
                    }

                    printf("\n		->Lendo o txt...\n\n");

                    while((fscanf(f1,"%d %d %d",&grafo_node->grafo_saida, &grafo_node->grafo_chegada, &grafo_node->peso)) != EOF){
                        grafo_matriz_node->m[grafo_node->grafo_saida][grafo_node->grafo_chegada] = 1;
                        grafo_matriz_node->m[grafo_node->grafo_chegada][grafo_node->grafo_saida] = 1;
                        grafo_matriz_node->peso[grafo_node->grafo_saida][grafo_node->grafo_chegada] = grafo_node->peso;
                        printf("Grafo:%d vertice:%d peso:%d\n",grafo_node->grafo_saida,grafo_node->grafo_chegada, grafo_node->peso);
                    }

                    fclose(f1);
                }
                __grafo_foi_lido__ = true;

            } else {
                free(grafo_matriz_node);
                grafo_matriz_node = (struct matriz*)malloc(sizeof(struct matriz));

                printf("\n		->Lendo o txt...\n\n");
                //fscanf(f1, "%c", &flag);
                //fscanf(f1, "%*[^\n]\n", NULL);
                fscanf(f1, "%d", &grafo_node->tipo);
                fscanf(f1, "%d", &grafo_matriz_node->tamanho);

                grafo_matriz_node->tipo = grafo_node->tipo;

                if(grafo_node->tipo == 1) {
                    printf("\ntipo do grafo: digrafo\n");

                    printf("tamanho: %d\n", grafo_matriz_node->tamanho);

                    for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                        for (j = 0; j < grafo_matriz_node->tamanho; j++) {

                            grafo_matriz_node->m[i][j] = 0;
                            grafo_matriz_node->peso[i][j] = 0;
                            grafo_matriz_node->visitado[i] = 0;

                            if(debug){
                                printf("L:%d C:%d V:%d\n",i,j,grafo_matriz_node->m[i][j]);
                            }

                        }
                    }

                    while((fscanf(f1,"%d %d %d",&grafo_node->grafo_saida, &grafo_node->grafo_chegada, &grafo_node->peso)) != EOF){
                        grafo_matriz_node->m[grafo_node->grafo_saida][grafo_node->grafo_chegada] = 1;
                        grafo_matriz_node->peso[grafo_node->grafo_saida][grafo_node->grafo_chegada] = grafo_node->peso;
                        printf("Grafo:%d vertice:%d peso:%d\n",grafo_node->grafo_saida,grafo_node->grafo_chegada, grafo_node->peso);
                    }

                    fclose(f1);

                } else {
                    printf("\ntipo do grafo: grafo\n");

                    printf("tamanho: %d\n", grafo_matriz_node->tamanho);

                    for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                        for (j = 0; j < grafo_matriz_node->tamanho; j++) {

                            grafo_matriz_node->m[i][j] = 0;
                            grafo_matriz_node->peso[i][j] = 0;

                            if(debug){
                                printf("L:%d C:%d V:%d\n",i,j,grafo_matriz_node->m[i][j]);
                            }

                        }
                    }

                    printf("\n		->Lendo o txt...\n\n");

                    while((fscanf(f1,"%d %d %d",&grafo_node->grafo_saida, &grafo_node->grafo_chegada, &grafo_node->peso)) != EOF){
                        grafo_matriz_node->m[grafo_node->grafo_saida][grafo_node->grafo_chegada] = 1;
                        grafo_matriz_node->m[grafo_node->grafo_chegada][grafo_node->grafo_saida] = 1;
                        grafo_matriz_node->peso[grafo_node->grafo_saida][grafo_node->grafo_chegada] = grafo_node->peso;
                        printf("Grafo:%d vertice:%d peso:%d\n",grafo_node->grafo_saida,grafo_node->grafo_chegada, grafo_node->peso);
                    }

                    fclose(f1);
                }

            }

            for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                for(j = 0; j < grafo_matriz_node->tamanho; j++) {
                    if(grafo_matriz_node->peso[i][j] != 0 && grafo_matriz_node->m[i][j] == 1){
                        grafo_matriz_node->contem_peso = 1;
                    }
                }
            }

            printf("\n");
            pause();

        } else {
            printf("\n		-> **erro, nao foi possivel abrir o arquivo de txt...\n\n");
            fclose(f1);

            pause();
        }
    }
}

// Cria um grafo com valores que usuario escrever.
void criar_grafo(int op){
    strcat(__function_flow__,"       |--> criar_grafo(int op) - Onde o grafo eh criado.\n");
    fflush(stdin);

    int i = 0;
    int j = 0;

    if(op == 1) {
        int __num_vertices__ = 0;
        int __conectar_vertice__ = 0;
        int __tem_peso__ = 0;
        int __peso__ = 0;

        printf("Function atual: criar_grafo();\n");
        printf("\nCriando um digrafo...\n");
        printf("Digite o nome do arquivo!\n>: ");
        scanf("%s",file_name);

        if( (f2 = fopen(file_name,"w+")) != NULL){

            printf("\nDigite a quantidade de vertices\n>: ");
            scanf("%d",&__num_vertices__);
            fprintf(f2, "%d\n",1);
            fprintf(f2, "%d\n",__num_vertices__);

            for(i = 0; i < __num_vertices__; i++) {
                for(j = 0; j < __num_vertices__; j++) {
                    printf("\nLigar a vertice [%d] com a vertice [%d] ? [1 para sim e 0 para nao]\n>: ",i,j);
                    scanf("%d",&__conectar_vertice__);

                    if(__conectar_vertice__ == 1) {
                        printf("\nO vertice tem  que peso ?[1 para sim e 0 para nao]\n>: ");
                        scanf("%d",&__tem_peso__);

                        if(__tem_peso__ == 1){
                            printf("\nQual o peso do vertice [%d] ?\n>: ",i);
                            scanf("%d",&__peso__);
                            fprintf(f2, "%d %d %d\n",i,j,__peso__);
                        } else {
                            fprintf(f2, "%d %d %d\n",i,j,0);
                        }
                    }
                }
            }

            printf("Arquivo \"%s\" criado com sucesso!\n", file_name);
            pause();

        } else {
            printf("\n		-> **error, nao foi possivel criar o arquivo de txt...\n\n");
            pause();

        }

        fclose(f2);
    } else if(op == 2){
        int __num_vertices__ = 0;
        int __conectar_vertice__ = 0;
        int __tem_peso__ = 0;
        int __peso__;

        printf("Function atual: criar_grafo();\n");
        printf("\nCriando um grafo...\n");
        printf("Digite o nome do arquivo!\n>: ");
        scanf("%s",file_name);

        if( (f2 = fopen(file_name,"w+")) != NULL){

            printf("\nDigite a quantidade de vertices\n>: ");
            scanf("%d",&__num_vertices__);
            fprintf(f2, "%d\n",0);
            fprintf(f2, "%d\n",__num_vertices__);

            for(i = 0; i < __num_vertices__; i++) {
                for(j = 0; j < __num_vertices__; j++) {
                    printf("\nLigar a vertice [%d] com a vertice [%d] ? [1 para sim e 0 para nao]\n>: ",i,j);
                    scanf("%d",&__conectar_vertice__);

                    if(__conectar_vertice__ == 1) {
                        printf("\nO vertice tem  que peso ?[1 para sim e 0 para nao]\n>: ");
                        scanf("%d",&__tem_peso__);

                        if(__tem_peso__ == 1){
                            printf("\nQual o peso do vertice [%d] ?\n>: ",i);
                            scanf("%d",&__peso__);
                            fprintf(f2, "%d %d %d\n",i,j,__peso__);
                        } else {
                            fprintf(f2, "%d %d %d\n",i,j,0);
                        }
                    }
                }
            }

            printf("Arquivo \"%s\" criado com sucesso!\n", file_name);

            pause();


        } else {
            printf("\n		-> **error, nao foi possivel criar o arquivo de txt...\n\n");

            pause();

        }

        fclose(f2);
    }

}

// Atualiza as vertices do grafo, direto na matriz de adjacencia.
void atualiza_vertices(struct matriz *grafo_matriz_node){
    int quantidade_vertice = 0;

    printf("->Digite a quantidade de vertice para adicionar ao tamanho original\n->Digite 0 para modificar o grafo com o tamanho atual\n->Digite -1 para voltar\n>: ");
    scanf("%d",&quantidade_vertice);

    if(quantidade_vertice != -1) {
        grafo_matriz_node->tamanho = grafo_matriz_node->tamanho + quantidade_vertice;

        printf("Informe se em quais vertices novos serao ligados aos antigos.\n");

        int i = 0;
        int j = 0;
        int resp = 0;

        for(i = 0; i < grafo_matriz_node->tamanho; i++) {
            for(j = 0; j < grafo_matriz_node->tamanho; j++) {
                printf("Vertice %d -> %d\n> 1 para sim 0 para nao <\n>: ",i,j);
                scanf("%d",&resp);

                if(resp == 1) {
                    grafo_matriz_node->m[i][j] = 1;

                    printf("A ligacao de vertices feita tem peso ?  1 para sim 0 para nao\n>: ");
                    scanf("%d", &resp);

                    if(resp == 1) {
                        int peso;

                        printf("**  Atencao: numero dos pesos apenas numeros positivos de 0 - 999  **\n");
                        printf("Digite o valor do peso da aresta que liga %d com %d.\n>: ",i,j);
                        scanf("%d", &peso);

                        grafo_matriz_node->peso[i][j] = peso;
                    }
                } else {
                    grafo_matriz_node->m[i][j] = 0;
                    grafo_matriz_node->peso[i][j] = 0;
                }
            }
            printf("Grafo atualizado com sucesso!\n");
            pause();

        }
        printf("\n**  Fim da atualizacao de vertices.  **\n");
        printf("O novo tamanho eh %d",grafo_matriz_node->tamanho);
        printf("\n Necessario realizar os algoritmos de buscas novamente, caso queria visualizar a tabela desse novo grafo.\n");
        pause();

    }
}

// Cria um arquivo e salva a tabela BFS nele.
void criar_arquivo__tabela_bfs(struct BFS_data *bfs_tabela){
    int i = 0;

    strcpy(file_name, "BFS-");
    char local_file_name[50];

    strcat(__function_flow__,"       |--> criar_arquivo__tabela_dfs(struct BFS_data *dfs_tabela) - Escrevendo a tabela BFS.\n");
    fflush(stdin);

    printf("Function atual: criar_arquivo__tabela_bfs();\n");
    fflush(stdin);

    printf("Digite o nome do arquivo!\n>: ");
    scanf("%s",local_file_name);

    strcat(file_name, local_file_name);

    if(debug == true)
        printf("\nNome do arquivo: %s\n",file_name);

    printf("\n		->Criando o txt...\n\n");

    if((f2 = fopen(file_name, "w+")) != NULL){
        printf("\nEscrevendo a tabela...\n");

        fprintf(f2,"%d\n",bfs_tabela->origem);
        for(i = 0; i < bfs_tabela->tamanho; i++){
            fprintf(f2,"%d %c %d %d\n", bfs_tabela->vertice[i], bfs_tabela->indice_cor[i], bfs_tabela->distancia[i], bfs_tabela->pai[i]);
        }

        printf("\nEscrita finalizada!\n");
        pause();


        fclose(f2);


    } else {
        printf("\n		-> **erro, nao foi possivel criar o arquivo de txt...\n\n");
        pause();

        fclose(f2);
    }
}

// Realiza uma leitura em um arquivo com uma tabela BFS.
void ler_busca_bfs(struct BFS_data *bfs_tabela){
    strcat(__function_flow__,"       |--> ler_busca_bfs(struct matriz *aux_matriz, struct BFS_data *bfs_tabela) - Lendo um arquivo com busca BFS.\n");
    fflush(stdin);
    int i =0;

    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(".");
    printf("Function atual: ler_busca_bfs();\n");
    printf("      **Arquivos de txt no mesmo diretorio**\n");
    printf(" >:Encontrados:\n\n");
    while ( ( lsdir = readdir(dir) ) != NULL ) {
        if(endsWithSuffix (lsdir->d_name,".txt")){
            printf ("%s\n", lsdir->d_name);
        }
    }
    printf("\nDigite o  nome do arquivo de texto a ser aberto: ");
    scanf("%s", file_name);
    fflush(stdin);

    printf("\n");

    if (!endsWithSuffix (file_name,".txt")) {
        printf("Erro - \"%s\" parece nao ser um arquivo txt valido...\n", file_name);
        fclose(f1);
        pause();
    } else {
        if((f1 = fopen(file_name, "r+")) != NULL){
            printf("\n		->Lendo o txt...\n\n");

            int __tamanho_tabela__ = 0;
            int vertice[30];
            int pai[30];
            int distancia[30];
            char indice_cor[30];


            fscanf(f1, "%d", &bfs_tabela->origem);

            while(!feof(f1)){
                fscanf(f1, "%d %c %d %d",&vertice[__tamanho_tabela__]
                        ,&indice_cor[__tamanho_tabela__]
                        ,&distancia[__tamanho_tabela__]
                        ,&pai[__tamanho_tabela__]);

                __tamanho_tabela__++;
            }

            for(i = 0; i < __tamanho_tabela__-1; i++){
                bfs_tabela->vertice[i] = vertice[i];
                bfs_tabela->indice_cor[i] = indice_cor[i];
                bfs_tabela->distancia[i] = distancia[i];
                bfs_tabela->pai[i] = pai[i];

                if(debug == true) {
                    printf("Vertice: %d\n", bfs_tabela->vertice[i]);
                    printf("Cor: %c\n",bfs_tabela->indice_cor[i]);
                    printf("Distancia: %d\n",bfs_tabela->distancia[i]);
                    printf("Pai: %d\n\n",bfs_tabela->pai[i]);
                }
            }

            bfs_tabela->tamanho = __tamanho_tabela__-1;

            fclose(f1);

            int t = 0;

            printf("Function atual: print_tabela_dfs();\n");
            printf("           *Busca em Largura - Tabela*         \n");
            printf("Caso queira ver a tabela no cmd em janela cheia, siga as intrucoes abaixo:\n\n");
            printf("--> Pressione ENTER depois de maximizar a tela de prompt\npara que a formatacao nao seja estragada.\n");
            printf("\n* Aperte ENTER para continuar *\n");
            getchar();
            printf("Origem: %d\n",bfs_tabela->origem);
            printf("Obs: -1 == NULL\n\n");
            printf("*******************************************************\n");
            printf("*  Vertices  || Cor ||   Distancia  ||       Pai      *\n");
            printf("*******************************************************\n");

            for (t = 0; t < bfs_tabela->tamanho; t++) {
                printf("     %.3d     ||  %c  ||     %.3d      ||      %.3d       \t\n", bfs_tabela->vertice[t], bfs_tabela->indice_cor[t], bfs_tabela->distancia[t], bfs_tabela->pai[t]);
            }

            printf("*******************************************************\n");

            __is_bfs_created__ = true;

            pause();


        } else {
            printf("\n		-> **erro, nao foi possivel abrir o arquivo de txt...\n\n");
            pause();

            fclose(f1);
        }
    }
}

// Acessa a function bfs() para realizar uma busca em largura.
void realizar_uma_busca_bfs(struct auxiliar_matriz *aux2_matriz, struct BFS_data *bfs_tabela){
    int i = 0;

    strcat(__function_flow__,"       |--> realizar_uma_busca_dfs(struct matriz *aux_matriz, struct DFS_data *dfs_tabela) - Criando a tabela.\n");
    fflush(stdin);

    bfs_tabela->tamanho = aux2_matriz->tamanho;


    printf("Function atual: realizar_uma_busca_bfs();\n");
    fflush(stdin);

    for(i = 0; i < bfs_tabela->tamanho; i++){
        bfs_tabela->vertice[i] = i;
        bfs_tabela->caminho[i] = -1;
    }

    if(debug == true){
        printf("\n\nTabela:\n");
        for(i = 0; i < bfs_tabela->tamanho; i++){
            printf("indice: %d",bfs_tabela->vertice[i]);
            printf("indice: %d",bfs_tabela->caminho[i]);
        }
    }

    BF_Traversal(aux2_matriz, bfs_tabela,debug);

    printf(" Busca realizada com sucesso!\n");
    pause();


    __is_bfs_created__ = true;
}

// Printa a tabela BFS no Console
void print_tabela_bfs(struct BFS_data *bfs_tabela) {
    strcat(__function_flow__,"       |--> print_tabela_bfs(struct BFS_data* bfs_tabela) - Print da tabela BFS no console.\n");
    fflush(stdin);

    int i = 0;
    int t = 0;

    printf("Function atual: print_tabela_dfs();\n");
    printf("           *Busca em Largura - Tabela*         \n");
    printf("Caso queira ver a tabela no cmd em janela cheia, siga as intrucoes abaixo:\n\n");
    printf("--> Pressione ENTER depois de maximizar a tela de prompt\npara que a formatacao nao seja estragada.\n");
    printf("\n* Aperte ENTER para continuar *\n");
    getchar();
    printf("Origem: %d\n",bfs_tabela->origem);
    printf("Obs: -1 == NULL\n\n");
    printf("*******************************************************\n");
    printf("*  Vertices  || Cor ||   Distancia  ||       Pai      *\n");
    printf("*******************************************************\n");

    for (t = 0; t < bfs_tabela->tamanho; t++) {
        printf("     %.3d     ||  %c  ||     %.3d      ||      %.3d       \t\n", bfs_tabela->vertice[t], bfs_tabela->indice_cor[t], bfs_tabela->distancia[t], bfs_tabela->pai[t]);
    }

    printf("*******************************************************\n");

    if(debug == true){
        for(i = 0; i < bfs_tabela->tamanho; i++) {
            printf("Vertice: %d\n", bfs_tabela->vertice[i]);
            printf("Cor: %c\n",bfs_tabela->indice_cor[i]);
            printf("Distancia: %d\n",bfs_tabela->distancia[i]);
            printf("Pai: %d\n\n",bfs_tabela->pai[i]);
        }
    }

    pause();

}
// FIM DOS ALGORITMOS BFS


// INCIO ALGORITMOS DFS
// Cria um arquivo e salva a tabela DFS nele.
void criar_arquivo__tabela_dfs(struct DFS_data *dfs_tabela){
    int i = 0;

    strcpy(file_name, "DFS-");
    char local_file_name[50];

    strcat(__function_flow__,"       |--> criar_arquivo__tabela_dfs(struct DFS_data *dfs_tabela) - Escrevendo a tabela DFS.\n");
    fflush(stdin);

    printf("Function atual: criar_arquivo__tabela_dfs();\n");
    fflush(stdin);

    printf("Digite o nome do arquivo!\n>: ");
    scanf("%s",local_file_name);

    strcat(file_name, local_file_name);

    if(debug == true)
        printf("\nNome do arquivo: %s\n",file_name);

    printf("\n		->Criando o txt...\n\n");

    if((f2 = fopen(file_name, "w+")) != NULL){
        printf("\nEscrevendo a tabela...\n");

        fprintf(f2,"%d\n",dfs_tabela->origem);
        for(i = 0; i < dfs_tabela->tamanho; i++){
            fprintf(f2,"%d %c %d %d\n", i, dfs_tabela->indice_cor[i], dfs_tabela->descoberta[i], dfs_tabela->finalizacao[i]);
        }

        printf("\nEscrita finalizada!\n");
        pause();
        fclose(f2);


    } else {
        printf("\n		-> **erro, nao foi possivel criar o arquivo de txt...\n\n");
        pause();
        fclose(f2);
    }
}

// Realiza uma leitura em um arquivo com uma tabela DFS.
void ler_busca_dfs(struct DFS_data *dfs_tabela){
    strcat(__function_flow__,"       |--> ler_busca_dfs(struct matriz *aux_matriz, struct DFS_data *dfs_tabela) - Lendo um arquivo com busca DFS.\n");
    fflush(stdin);
    int i =0;

    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(".");
    printf("Function atual: ler_busca_dfs();\n");
    printf("      **Arquivos de txt no mesmo diretorio**\n");
    printf(" >:Encontrados:\n\n");
    while ( ( lsdir = readdir(dir) ) != NULL ) {
        if(endsWithSuffix (lsdir->d_name,".txt")){
            printf ("%s\n", lsdir->d_name);
        }
    }
    printf("\nDigite o  nome do arquivo de texto a ser aberto: ");
    scanf("%s", file_name);
    fflush(stdin);

    printf("\n");

    if (!endsWithSuffix (file_name,".txt")) {
        printf("Erro - \"%s\" parece nao ser um arquivo txt valido...\n", file_name);
        fclose(f1);
        pause();
    } else {
        if((f1 = fopen(file_name, "r+")) != NULL){
            printf("\n		->Lendo o txt...\n\n");

            int __tamanho_tabela__ = 0;
            char indice_cor[30];

            int indice[30];
            int descoberta[30];
            int finalizacao[30];

            fscanf(f1, "%d", &dfs_tabela->origem);

            while(!feof(f1)){
                fscanf(f1, "%d %c %d %d",&indice[__tamanho_tabela__]
                        ,&indice_cor[__tamanho_tabela__]
                        ,&descoberta[__tamanho_tabela__]
                        ,&finalizacao[__tamanho_tabela__]);

                __tamanho_tabela__++;
            }

            int t = 0;
            printf("Origem: %d\n\n",dfs_tabela->origem);
            printf("           *Busca em Profundidade - Tabela*         \n");
            printf("Caso queira ver a tabela no cmd em janela cheia, siga as intrucoes abaixo:\n\n");
            printf("--> Pressione ENTER depois de maximizar a tela de prompt\npara que a formatacao nao seja estragada.\n");
            printf("\n* Aperte ENTER para continuar *\n");
            getchar();
            printf("*******************************************************\n");
            printf("*  Vertices  || Cor ||  Descoberta  ||  Finalizacao   *\n");
            printf("*******************************************************\n");

            for (t = 0; t < __tamanho_tabela__ - 1; t++)
            {

                printf("*    %.3d     ||  %c  ||     %.3d      ||     %.3d       *\n", indice[t], indice_cor[t], descoberta[t], finalizacao[t]);
            }

            printf("*******************************************************\n");

            for(i = 0; i < __tamanho_tabela__-1; i++){

                dfs_tabela->indice[i] = indice[i];
                dfs_tabela->indice_cor[i] = indice_cor[i];
                dfs_tabela->descoberta[i] = descoberta[i];
                dfs_tabela->finalizacao[i] = finalizacao[i];


            }

            dfs_tabela->tamanho = __tamanho_tabela__-1;

            fclose(f1);

            __is_dfs_created__ = true;

            pause();

        } else {
            printf("\n		-> **erro, nao foi possivel abrir o arquivo de txt...\n\n");
            pause();
            fclose(f1);
        }
    }
}

// Acessa a function dfs() para realizar uma busca de profundidade.
void realizar_uma_busca_dfs(struct auxiliar_matriz *aux2_matriz, struct DFS_data *dfs_tabela){
    int i = 0;

    strcat(__function_flow__,"       |--> realizar_uma_busca_dfs(struct matriz *aux_matriz, struct DFS_data *dfs_tabela) - Criando a tabela.\n");
    fflush(stdin);

    dfs_tabela->tamanho = aux2_matriz->tamanho;


    printf("Function atual: realizar_uma_busca_dfs();\n");
    fflush(stdin);

    for( i = 0; i < dfs_tabela->tamanho; i++){
        dfs_tabela->indice[i] = i;
        dfs_tabela->caminho[i] = -1;
    }

    printf("Digite a origem para fazer a busca por profundidade: ");
    scanf("%d", &dfs_tabela->origem);
    printf("\n\n A origem escolhida foi %d!\n\n",dfs_tabela->origem);

    dfs(aux2_matriz,dfs_tabela->origem,dfs_tabela,debug);

    if(debug == true){
        printf("\n\nTabela:\n");
        for(i = 0; i < dfs_tabela->tamanho; i++){
            printf("Indice: %d\n",dfs_tabela->indice[i]);
            printf("descoberta: %d\n",dfs_tabela->descoberta[i]);
            printf("finalizacao: %d\n",dfs_tabela->finalizacao[i]);
            printf("cor: %c\n\n",dfs_tabela->indice_cor[i]);
        }
    }
    printf(" Busca realizada com sucesso!\n");
    pause();

    __is_dfs_created__ = true;
}

// Print na tela de uma tabela DFS.
void print_tabela_dfs(struct DFS_data *dfs_tabela){

    strcat(__function_flow__,"       |--> print_tabela_dfs(struct DFS_data* dfs_tabela) - Print da tabela DFS no console.\n");
    fflush(stdin);

    int i = 0;
    int t = 0;

    printf("Function atual: print_tabela_dfs();\n");
    printf("           *Busca em Profundidade - Tabela*         \n");
    printf("Caso queira ver a tabela no cmd em janela cheia, siga as intrucoes abaixo:\n\n");
    printf("--> Pressione ENTER depois de maximizar a tela de prompt\npara que a formatacao nao seja estragada.\n");
    printf("\n* Aperte ENTER para continuar *\n");
    getchar();
    printf("Origem: %d\n\n",dfs_tabela->origem);
    printf("******************************************************\n");
    printf("*  Vertices  || Cor ||  Descoberta  ||  Finalizacao  *\n");
    printf("******************************************************\n");

    for (t = 0; t < dfs_tabela->tamanho; t++)
    {

        printf("*    %.3d     ||  %c  ||     %.3d      ||     %.3d       *\n", dfs_tabela->indice[t], dfs_tabela->indice_cor[t], dfs_tabela->descoberta[t], dfs_tabela->finalizacao[t]);
    }

    printf("******************************************************\n");

    if(debug == true) {
        for(i = 0; i < dfs_tabela->tamanho; i++){
            printf("Indice: %d\n",dfs_tabela->indice[i]);
            printf("descoberta: %d\n",dfs_tabela->descoberta[i]);
            printf("finalizacao: %d\n",dfs_tabela->finalizacao[i]);
            printf("cor: %c\n\n",dfs_tabela->indice_cor[i]);
        }
    }

    pause();
}

// FIM ALGORITMOS DFS

// Function resposavel por realizar operacoes ou chamar outras functions para realizar operacoes pedidas no trabalho.
int grafos(int option,int __local_option__, struct info__matriz *grafo_node,struct matriz *grafo_matriz_node, struct DFS_data *dfs_tabela, struct BFS_data *bfs_tabela){

    int i = 0;
    int j = 0;

    int op;          // Variavel para determinar a escolha do usuario em relacao ao do{}while mais externo.
    int __local_while_op__; // Variavel para determinar a escolha do usuario em relacao ao do{}while mais interno.

    struct matriz *aux_matriz;
    aux_matriz = grafo_matriz_node;

    if (option == 1 && __local_option__ == 1) { // criar um digrafo
        clrscr();
        criar_grafo(__local_option__);

    } else if(option == 1 && __local_option__ == 2) { // criar um digrafo
        clrscr();
        criar_grafo(__local_option__);

    } else if(option == 1 && __local_option__ == 3) { // ler um grafo ou digrafo
        clrscr();
        ler_grafo(grafo_node, grafo_matriz_node);

    } else if(option == 2 && __local_option__ == 1) { // Mostra uma matriz de adjacencia
        clrscr();

        printf("Function atual: grafos();\n");
        printf("\n		->Printando a matriz de adjacenca...\n\n");
        printf("tamanho: %d por %d\n", grafo_matriz_node->tamanho,grafo_matriz_node->tamanho);
        for(i = 0; i < grafo_matriz_node->tamanho; i++){
            if(i == 0) {
                printf("  C ");
            } else if (i == grafo_matriz_node->tamanho-1) {
                printf("C\n");
            } else {
                printf("C ");
            }
        }
        for(i = 0; i < grafo_matriz_node->tamanho; i++) {
            printf("L ");
            for (j = 0; j < grafo_matriz_node->tamanho; j++) {
                printf("%d ",grafo_matriz_node->m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        pause();
    } else if(option == 2 && __local_option__ == 2){
        ler_matriz(grafo_matriz_node);
    } else if(option == 2 && __local_option__ == 3) {
        escrever_matriz(grafo_matriz_node);
    } else if (option == 3 && __local_option__ == 1) { // realizar uma busca de profundidade

        do{
            clrscr();
            printf("Function atual: grafos();\n");
            printf("\n     **Foi escolhdio 3-1) Busca por profundidade.**\n\n");
            printf("1 -> Ler uma tabela de um arquivo de texto.\n");
            printf("2 -> Escrever uma tabela em um arquivo de texto.\n");
            printf("3 -> Criar a tabela - Algoritmo busca por profundidade.\n");
            printf("4 -> Mostrar a tabela.\n\n");
            printf("0 -> sair\n\n");

            printf("  **Digite sua escolha\n>: ");
            scanf("%d",&__local_while_op__);

            if(__local_while_op__ == 1){ // Lendo uma tabela de um arquivo de texto

                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Ler uma tabela DFS em um arquivo.\n");
                fflush(stdin);

                clrscr();
                ler_busca_dfs(dfs_tabela);

            } else if(__local_while_op__ == 2) { // Escrevendo uma tabela em um arquivo de texto.
                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Escrever a tabela DFS em um arquivo.\n");
                fflush(stdin);

                clrscr();
                criar_arquivo__tabela_dfs(dfs_tabela);

            } else if(__local_while_op__ == 3) { // Opcao aonde ocorre a criacao da tabela
                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Criar a tabela - Algoritmo busca por profundidade.\n");
                fflush(stdin);

                clrscr();

                aux2_matriz->tamanho = grafo_matriz_node->tamanho;

                for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                    for (j = 0; j < grafo_matriz_node->tamanho; j++) {

                        aux2_matriz->m[i][j] = grafo_matriz_node->m[i][j];
                        aux2_matriz->peso[i][j] = grafo_matriz_node->peso[i][j];


                        if(debug){
                            printf("L:%d C:%d V:%d\n",i,j,aux2_matriz->m[i][j]);
                        }
                    }
                    aux2_matriz->indice[i] = grafo_matriz_node->indice[i];
                    aux2_matriz->visitado[i] = grafo_matriz_node->visitado[i];
                }

                realizar_uma_busca_dfs(aux2_matriz, dfs_tabela);

            } else if(__local_while_op__ == 4) {
                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Mostrar a tabela - Algoritmo busca por profundidade.\n");
                fflush(stdin);

                clrscr();
                if(__is_dfs_created__ == true) {
                    print_tabela_dfs(dfs_tabela);
                    __is_dfs_created__ = false;
                } else {
                    printf("\nE necessario ler uma tabela de um arquivo txt ou criar uma tabela a partir de uma\n matriz de adjacencia para dar print nela.\n\n");
                }

            }

        }while(__local_while_op__ != 0);

    } else if (option == 3 && __local_option__ == 2) { // realizar uma busca em largura

        do{
            clrscr();
            printf("Function atual: grafos();\n");
            printf("\n     **Foi escolhdio 3-2) Busca por largura.**\n\n");
            printf("1 -> Ler uma tabela de um arquivo de texto.\n");
            printf("2 -> Escrever uma tabela em um arquivo de texto.\n");
            printf("3 -> Criar a tabela - Algoritmo busca por largura.\n");
            printf("4 -> Mostrar a tabela.\n\n");
            printf("0 -> sair\n\n");

            printf("  **Digite sua escolha\n>: ");
            scanf("%d",&__local_while_op__);

            if(__local_while_op__ == 1){ // Lendo uma tabela de um arquivo de texto

                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Ler uma tabela BFS em um arquivo.\n");
                fflush(stdin);

                clrscr();
                ler_busca_bfs(bfs_tabela);

            } else if(__local_while_op__ == 2) { // Escrevendo uma tabela em um arquivo de texto.
                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Escrever a tabela BFS em um arquivo.\n");
                fflush(stdin);

                clrscr();
                criar_arquivo__tabela_bfs(bfs_tabela);

            } else if(__local_while_op__ == 3) { // Opcao aonde ocorre a criacao da tabela
                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Criar a tabela - Algoritmo busca por largura.\n");
                fflush(stdin);

                clrscr();
                aux2_matriz->tamanho = grafo_matriz_node->tamanho;

                for(i = 0; i < grafo_matriz_node->tamanho; i++) {
                    for (j = 0; j < grafo_matriz_node->tamanho; j++) {

                        aux2_matriz->m[i][j] = grafo_matriz_node->m[i][j];
                        aux2_matriz->peso[i][j] = grafo_matriz_node->peso[i][j];

                        if(debug){
                            printf("L:%d C:%d V:%d\n",i,j,aux2_matriz->m[i][j]);
                        }
                    }
                    aux2_matriz->visitado[i] = grafo_matriz_node->visitado[i];
                    aux2_matriz->indice[i] = i;
                }

                realizar_uma_busca_bfs(aux2_matriz, bfs_tabela);

            } else if(__local_while_op__ == 4) {
                strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Mostrar a tabela - Algoritmo busca por largura.\n");
                fflush(stdin);

                clrscr();
                if(__is_bfs_created__ == true) {
                    print_tabela_bfs(bfs_tabela);
                    __is_bfs_created__ = false;
                } else {
                    printf("\nE necessario ler uma tabela de um arquivo txt ou criar uma tabela a partir de uma\n matriz de adjacencia para dar print nela.\n\n");
                }

            }

        }while(__local_while_op__ != 0);
        printf("\nAlgorimto n implementado\n");

    } else if (option == 4 && __local_option__ == 3) { // Caminho da busca em profundidade
        strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Caminho da busca em profundidade.\n");
        fflush(stdin);
        clrscr();

        printf("\n\nCaminho realizado na DFS:\n");
        for(i = 0; i < dfs_tabela->tamanho; i++){
            if(i+1 == dfs_tabela->tamanho) {
                //printf("%d",dfs_tabela->caminho[i]);
                printf("%d",dfs_caminho[i]);
            } else {
                //printf("%d->",dfs_tabela->caminho[i]);
                printf("%d->",dfs_caminho[i]);
            }
        }

        printf("\n\n");
        pause();

    } else if (option == 4 && __local_option__ == 4) { // Caminho da busca em largura
        strcat(__function_flow__,"    |--> grafos(op,__local_while_op__, grafo_node, grafo_matriz_node) - Caminho da busca em largura.\n");
        fflush(stdin);
        clrscr();
        printf("\n\nCaminho realizado:\n");
        for(i = 0; i < bfs_tabela->tamanho; i++) {
            if(i+1 == bfs_tabela->tamanho){
                printf("%d", bfs_tabela->caminho[i]);
            } else {
                printf("%d->", bfs_tabela->caminho[i]);
            }
        }

        printf("\n\n");
        pause();
    }
    //pause();

    return 0;
}

int __Menu__(){
    int op;          // Variavel para determinar a escolha do usuario em relacao ao do{}while mais externo.
    int __local__op; // Variavel para determinar a escolha do usuario em relacao ao do{}while mais interno.

    char s[64];                                 // Variavel para pegar o valor da data e a hora do OS em questao
    char log_name[50] = {"Log [data/hora] = "}; // Variavel que vai dar nome ao arquivo do log.
    char replace1[] = "/";                      // Como a maioria dos OS nao suportam determinados
    char replace2[] = ":";                      // caracteres, estou utilizando duas variaveis pra
    // remover elas do nome do arquivo.

    // Criando o nome do arquivo de Log com a data e hora do dia em que o log foi criado.
    time_t t = time(NULL);                      // Setando a variavel t.
    struct tm *tm = localtime(&t);              // Pegando o tempo local.
    assert(strftime(s, sizeof(s), "%c", tm));   // Concatenando o tempo com a data atual.
    strcat(log_name,s);                         // Concatenando o nome do arquivo com o tempo e data atual da
    // string anterior.

    //Declarando as duas estruturas que realizaram e armazenaram os dados com as operacoes relacionadas a grafos.
    struct matriz *grafo_matriz_node = (struct matriz*)malloc(sizeof(struct matriz));               // Alocando memoria para as matrizes de adjacencia e de peso.
    aux2_matriz = (struct auxiliar_matriz*)malloc(sizeof(struct auxiliar_matriz));                  // Fazendo uma copia local
    struct info__matriz *grafo_node = (struct info__matriz*)malloc(sizeof(struct info__matriz));
    struct DFS_data *dfs_tabela = (struct DFS_data*)malloc(sizeof(struct DFS_data));
    struct BFS_data *bfs_tabela = (struct BFS_data*)malloc(sizeof(struct BFS_data));

    strcpy(log_name,replaceWord(log_name, replace1, "-")); // Removendo o / da string.
    strcpy(log_name,replaceWord(log_name, replace2, "-")); // Removendo o : da string.
    strcat(log_name,".txt");                               // Criando o nome final da string para nosso arquivo de log.

    if(debug)
        printf("%s\n",log_name);

    strcat(__function_flow__,"\n     **START LOG**     \n");
    strcat(__function_flow__,"\n-->__Menu__()\n");

    do{
        clrscr();
        printf("Function atual: __Menu__();\n");
        printf("\n     **Trabalho pratico de Estrutura de dados 2**\n\n");
        printf("1 -> Criar ou ler um grafo em um arquivo de texto.\n");
        printf("2 -> Operacoes com matrizes de adjacencia.\n");
        printf("3 -> Algoritmos de buscas nos grafos.\n");
        printf("4 -> Exibir o caminho.\n");
        printf("5 -> Verificacao de propriedades.\n");
        printf("6 -> Atualizar grafo.\n\n");
        printf("0 -> sair\n\n");

        printf("  **Digite sua escolha\n>: ");
        scanf("%d",&op);

        if(op == 1){
            do{
                clrscr();
                printf("Function atual: __Menu__();\n");
                printf("\n     **Foi escolhdio 1) Criar ou ler um grafo em um arquivo de texto.**\n\n");
                printf("1 -> Criar um digrafo.\n");
                printf("2 -> Criar um grafo.\n");
                printf("3 -> Ler um grafo.\n\n");
                printf("0 -> sair\n\n");

                printf("  **Digite sua escolha\n>: ");
                scanf("%d",&__local__op);

                if(__local__op == 1) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Criando um digrafo\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);
                } else if(__local__op == 2) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Criando um grafo\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);
                } else if(__local__op == 3) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Ler um grafo e criar sua matriz de adjacencia\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);
                }

            }while(__local__op != 0);
        } else if(op == 2) {
            do{
                clrscr();
                printf("Function atual: __Menu__();\n");
                printf("\n     **Foi escolhdio 2) Operacoes com matrizes de adjacencia.**\n\n");
                printf("1 -> Mostrar uma matriz de adjacencia.\n");
                printf("2 -> Ler uma matriz de adjacencia.\n");
                printf("3 -> Escrever uma matriz de adjacencia.\n");
                printf("0 -> sair\n\n");

                printf("  **Digite sua escolha\n>: ");
                scanf("%d",&__local__op);

                if(__local__op == 1){
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Mostra uma matriz de adjacencia\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);
                } else if(__local__op == 2) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Ler uma matriz de adjacencia.\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);

                } else if(__local__op == 3) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Escrever uma matriz de adjacencia.\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);

                }

            }while(__local__op != 0);
        } else if (op == 3) {

            do{
                clrscr();
                printf("Function atual: __Menu__();\n");
                printf("\n     **Foi escolhdio 3) Algoritmos de buscas nos grafos.**\n\n");
                printf("1 -> Algoritmo busca por profundidade.\n");
                printf("2 -> Algoritmo busca por largura.\n\n");
                printf("0 -> sair\n\n");

                printf("  **Digite sua escolha\n>: ");
                scanf("%d",&__local__op);

                if(__local__op == 1){
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - busca por profundidade.\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);

                } else if(__local__op == 2) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Algoritmo busca por largura\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);
                }

            }while(__local__op != 0);

        } else if (op == 4) {
            do{
                clrscr();
                printf("Function atual: __Menu__();\n");
                printf("\n     **Foi escolhdio 4) Exibir o caminho.**\n\n");

                printf("3 -> Caminho gerado pela DFS.\n");
                printf("4 -> Caminho gerado pela BFS.\n");
                printf("0 -> sair\n\n");

                printf("  **Digite sua escolha\n>: ");
                scanf("%d",&__local__op);

                if(__local__op == 3) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Caminho gerado pela DFS\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);

                } else if(__local__op == 4) {
                    strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) - Caminho gerado pela BFS\n");
                    fflush(stdin);

                    grafos(op,__local__op, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);

                }

            }while(__local__op != 0);
        } else if (op == 5) {
            clrscr();
            printf("Function atual: __Menu__();\n");
            printf("\n     **Foi escolhdio 5) Verificacao de propriedades.**\n\n");

            strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) Verificacao de propriedades.\n");
            fflush(stdin);//grafos(op,1, grafo_node, grafo_matriz_node, dfs_tabela, bfs_tabela);

            verificar_props(grafo_matriz_node);

        } else if (op == 6) {

            clrscr();
            printf("Function atual: __Menu__();\n");
            printf("\n     **Foi escolhdio 6) Atualizar grafo.**\n\n");

            strcat(__function_flow__,"  |--> grafos(op,__local__op, grafo_node, grafo_matriz_node) Atualizacao do grafo.\n");
            fflush(stdin);

            atualiza_vertices(grafo_matriz_node);

        }

    }while(op != 0);

    strcat(__function_flow__,"\n\n     **END LOG**     \n");
    __registrar_log__(__function_flow__, log_name);

    return op;
}


