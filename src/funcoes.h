/**
 * @file funcoes.h
 * @author Pedro Sousa (a31514@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 22-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "dados.h"

Elemento *CriaElemento(char tipo, int l, int c);

Elemento *InsereInicio(Elemento *inicio, Elemento *novo);

Elemento *InsereFim(Elemento *inicio, Elemento *novo);

Elemento *InsereOrdenado(Elemento *inicio, Elemento *novo);

Elemento *ProcurarElemento(Elemento *inicio, int l, int c);

Elemento *RemoverElemento(Elemento *inicio, int l, int c);

bool ListarMatriz(Elemento *inicio, Tamanho* matriz);

bool GravarElementoFicheiro(char* nomeFicheiro, Elemento* inicio, Tamanho* matriz);

Elemento *LerElementosFicheiro(char* nomeFicheiro, Tamanho* matriz);

