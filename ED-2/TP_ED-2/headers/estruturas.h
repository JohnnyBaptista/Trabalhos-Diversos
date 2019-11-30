//
// Created by ratob on 09/11/2019.
//

#ifndef NOVO_TPED2_ESTRUTURAS_H
#define NOVO_TPED2_ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct info__matriz{
    int grafo_saida;
    int grafo_chegada;
    int peso;
    int tipo;
}tm;

typedef struct matriz {
    int indice[30];
    int m[30][30];
    int peso[30][30];
    int tamanho;
    int visitado[30];
    int contem_peso;
    int origem;
    int numero_vertices;
    int numero_arestas;
    int tipo;
    char classificacao_grafo[50];

}ma;

typedef struct auxiliar_matriz {
    int indice[30];
    int m[30][30];
    int peso[30][30];
    int tamanho;
    int visitado[30];
    int contem_peso;
    int origem;
    int numero_vertices;
    int numero_arestas;
    int tipo;
    char classificacao_grafo[50];

}aux_ma;

typedef struct DFS_data{
    int origem;
    int tamanho;
    int tempo;
    int indice[30];
    char indice_cor[30];
    int descoberta[30];
    int finalizacao[30];
    int caminho[30];

    int dfs_esta_criada;
}dfs_struct;

typedef struct BFS_data{
    int origem;
    int tamanho;
    int tempo;
    int vertice[30];
    int pai[30];
    char indice_cor[30];
    int distancia[30];
    int caminho[30];

    int bfs_esta_criada;
}bfs_struct;

int dfs_caminho[30];

#endif //NOVO_TPED2_ESTRUTURAS_H
