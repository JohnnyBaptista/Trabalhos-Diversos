//
// Created by ratob on 09/11/2019.
//

#ifndef NOVO_TPED2_ALGORITMOS_DE_BUSCA_H
#define NOVO_TPED2_ALGORITMOS_DE_BUSCA_H

#include <stdio.h>
#include <stdlib.h>

void dfs(struct auxiliar_matriz *aux2_matriz,int origem, dfs_struct *dfs_tabela, bool debug);
void BF_Traversal(struct auxiliar_matriz *aux2_matriz, struct BFS_data *bfs_tabela, bool debug);

#endif //NOVO_TPED2_ALGORITMOS_DE_BUSCA_H
