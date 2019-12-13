//
// Created by ratob on 09/11/2019.
//

#include "headers/estruturas.h"
#include "headers/algoritmos_de_busca.h"

#define MAX 100

// Variaveis globais em algoritmos_de_busca.c
int contador_caminho = 0;
int fila[MAX];
int proximo = -1,anterior = -1;

// INICIO DO ALGORITMO DFS
void visit_dfs(struct auxiliar_matriz *aux2_matriz, int origem, dfs_struct *dfs_tabela, bool debug){
    dfs_tabela->indice_cor[origem] = 'c';
    dfs_tabela->tempo = dfs_tabela->tempo + 1;
    dfs_tabela->descoberta[origem] = dfs_tabela->tempo;

    if(debug == true){
        printf("\nAntes da Recursao.\n");
        printf("Origem:%d\n", origem);
        printf("Tempo; %d\n",dfs_tabela->tempo);
        printf("Ini; %d\n",dfs_tabela->descoberta[origem]);
        printf("Cor; %c\n",dfs_tabela->indice_cor[origem]);
    }


    dfs_caminho[contador_caminho] = origem;
    dfs_tabela->caminho[contador_caminho] = origem;


    int v = 0;
    for(v = 0; v < aux2_matriz->tamanho; v++){
        if(aux2_matriz->m[origem][v] == 1 && dfs_tabela->indice_cor[v] == 'b'){

            if(debug == true)
                printf("-> origem:%d v:%d cor:%c\n",origem,v,dfs_tabela->indice_cor[v]);

            contador_caminho++;
            visit_dfs(aux2_matriz, v, dfs_tabela, debug);
        }
    }

    dfs_tabela->indice_cor[origem] = 'p';
    dfs_tabela->tempo = dfs_tabela->tempo + 1;
    dfs_tabela->finalizacao[origem] = dfs_tabela->tempo;

    if(debug == true){
        printf("\nDepois da Recursao.");
        printf("Origem:%d\n", origem);
        printf("Tempo; %d\n",dfs_tabela->tempo);
        printf("Fim; %d\n",dfs_tabela->finalizacao[origem]);
        printf("Cor; %c\n",dfs_tabela->indice_cor[origem]);
    }
}

void dfs(struct auxiliar_matriz *aux2_matriz,int origem, dfs_struct *dfs_tabela, bool debug){
    int i = 0;
    int j = 0;


    dfs_tabela->tempo = 0;
    printf("Function atual: dfs(ma *aux_matriz);\n");

    for(i = 0; i < dfs_tabela->tamanho; i++) {
        dfs_tabela->indice_cor[i] = 'b';
    }

    for(j = 0; j < dfs_tabela->tamanho; j++){
        if(dfs_tabela->indice_cor[j] == 'b'){
            visit_dfs(aux2_matriz, origem, dfs_tabela, debug);
        }
    }


    if(debug == true) {
        printf("\n Caminho da busca por profundidade na function");
        for (j = 0; j< dfs_tabela->tamanho; j++){

            printf("%d->",dfs_caminho[j]);

        }

        printf("\n");

        printf("\n Caminho da busca por profundidade na tabela");
        for (j = 0; j< dfs_tabela->tamanho; j++){

            printf("%d->",dfs_tabela->caminho[j]);
        }

        printf("\n");
    }
}
// FIM DO ALGORITMO DFS

// INICIO DO ALGORITMO BFS
void inserir_fila(int vertex) {
    if(anterior == MAX-1)
        printf("Underflow na fila!!!!!\n");
    else {
        if(proximo == -1)
            proximo = 0;
        anterior = anterior+1;
        fila[anterior] = vertex ;
    }
}

int fila_esta_vazia() {
    if(proximo == -1 || proximo > anterior)
        return 1;
    else
        return 0;
}

int deletar_fila() {
    int deletar_item;
    if(proximo == -1 || proximo > anterior) {
        printf("Underflow na fila!!!!!\n");
    }

    deletar_item = fila[proximo];
    proximo = proximo+1;
    return deletar_item;
}

void BFS(int v, struct auxiliar_matriz *aux2_matriz, struct BFS_data *bfs_tabela, bool debug) {
    int i;
    int contador = 0;
    int distancia = 0;

    inserir_fila(v);
    bfs_tabela->indice_cor[v] = 'c';
    bfs_tabela->distancia[v] = distancia;
    bfs_tabela->pai[v] = -1;
    //state[v] = 'c';

    while(!fila_esta_vazia()) {
        v = deletar_fila();
        //printf("%d ",v);

        bfs_tabela->indice_cor[v] = 'p';
        //state[v] = 'p';
        bfs_tabela->caminho[contador] = v;
        contador++;
        //contador++;

        for(i=0; i< aux2_matriz->tamanho; i++) {
            if(aux2_matriz->m[v][i] == 1 && bfs_tabela->indice_cor[i] == 'b')  {
                //distancia++;
                inserir_fila(i);

                bfs_tabela->indice_cor[i] = 'c';
                bfs_tabela->distancia[i] = bfs_tabela->distancia[v] + 1;
                bfs_tabela->pai[i] = v;

                //distancia = 0;
            }
        }
    }
    printf("\n");

    if(debug == true){
        printf("Em BFS()\n");
        printf("Origem: %d\n\n",bfs_tabela->origem);
        for(i = 0; i < bfs_tabela->tamanho; i++) {
            printf("Vertice: %d\n", bfs_tabela->vertice[i]);
            printf("Cor: %c\n",bfs_tabela->indice_cor[i]);
            printf("Distancia: %d\n",bfs_tabela->distancia[i]);
            printf("Pai: %d\n\n",bfs_tabela->pai[i]);
        }
    }

}

void BF_Traversal(struct auxiliar_matriz *aux2_matriz, struct BFS_data *bfs_tabela, bool debug) {
    int i;

    for(i = 0; i < aux2_matriz->tamanho; i++)
        bfs_tabela->indice_cor[i] = 'b';

    printf("Digite a origem para fazer a busca em largura: ");
    scanf("%d", &bfs_tabela->origem);
    printf("\n\n A origem escolhida foi %d!\n\n",bfs_tabela->origem);

    BFS(bfs_tabela->origem, aux2_matriz, bfs_tabela, debug);


}

// FIM DO ALGORITMO BFS
