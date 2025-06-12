/**
 * @file grafo.h
 * @author Pedro Sousa (a31514@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 14-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once
#include "dados.h"

#pragma region ADJACENCIAS

/**
 * @brief Estrutura que representa uma adjacêcia de um vertice
 *
 */
typedef struct Adjacente
{
    int l, c; // coordenadas
    struct Adjacente *next;
} Adjacente;

Adjacente *CriarAdjacencia(int l, int c);

#pragma endregion

#pragma region VERTICES
/**
 * @brief Estrutura que representa um vértice
 *
 */
typedef struct Vertice
{
    char f;                  // frequencia
    int l, c;                // Coordenadas
    bool visitado;           // marcador
    struct Vertice *proximo; // Apontador para o próximo vertice
    struct Adjacente *next;  // Apontador para a próxima adjacência
} Vertice;

Vertice *CriarVertice(char f, int l, int c);
Vertice *ProcurarVertice(Vertice *inicio, int l, int c);
Vertice *InserirVertice(Vertice *novo, Vertice *inicio, int *res);
Vertice *RemoverVertice(Vertice *v, Vertice *inicio, int *res);

bool InserirAdjacencia(Vertice *origem, Adjacente *novo);
bool RemoverAdjacencia(Vertice *origem, Adjacente *adj);

#pragma endregion

#pragma region GRAFO

/**
 * @brief Estrutura que representa um grafo
 *
 */
typedef struct GR
{
    int numVertices;        // Número total de vertices
    struct Vertice *inicio; // Lista de vertices
} GR;

/**
 * @brief Estrutura que representa os caminhos percorridos pelo grafo
 *
 */
typedef struct Caminho
{
    Adjacente *inicio;       // Lista ligada com as coordenadas do caminho
    struct Caminho *proximo; // Próximo caminho na lista de caminhos
} Caminho;

GR *CriarGrafo(int numVertices);

bool GravarGrafo(char *nomeFicheiro, GR *grafo);
GR *LerGrafo(char *nomeFicheiro);

bool GravarGrafoFileTexto(char *nomeFicheiro, GR *grafo, Tamanho *matriz);
GR *LerGrafosFileTexto(char *nomeFicheiro, Tamanho *matriz);

bool MostrarLista(Adjacente *lista);
GR *InicializarVisitados(GR *grafo);
Adjacente *InserirCaminho(Adjacente *lista, int l, int c);
Adjacente *ProcuraEmProfundidade(GR *grafo, Vertice *origem);
bool dfs(Vertice *inicio, Vertice *origem, Adjacente **lista);

Adjacente *ProcuraEmLargura(GR *grafo, Vertice *origem);

Caminho *ProcurarTodosCaminhos(GR *grafo, Vertice *atual, Vertice *destino, Adjacente *caminhoAtual, Caminho *listaCaminhos);
Adjacente *Intersecoes(GR *grafo, char f1, char f2);
#pragma endregion