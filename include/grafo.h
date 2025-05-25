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
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#pragma region ADJACENCIAS
    
    typedef struct Adjacente {
        int l,c;//coordenadas
        struct Adjacente* next;
    }Adjacente;

    Adjacente* CriarAdjacencia(int l, int c);

#pragma endregion


#pragma region VERTICES
    
    typedef struct Vertice {
        char f;//frequencia
        int l,c;//Coordenadas
        bool visitado;//marcador
        struct Vertice* proximo;//Apontador para o próximo vertice
        struct Adjacente* next;//Apontador para a próxima adjacência
    }Vertice;

    Vertice* CriarVertice(char f, int l, int c);
    Vertice* ProcurarVertice(Vertice* inicio, int l, int c);
    bool InserirVertice(Vertice* novo, Vertice** inicio);
    bool RemoverVertice(Vertice* v, Vertice** inicio);

    bool InserirAdjacencia(Vertice* origem, Adjacente* novo);
    bool RemoverAdjacencia(Vertice* origem, Adjacente* adj);
    
#pragma endregion

#pragma region GRAFO
    
    typedef struct GR {
        int numVertices;//Número total de vertices
        Vertice* inicio;//Lista de vertices
    }GR;

    GR* CriarGrafo(int numVertices);
    bool GravarGrafo(char* nomeFicheiro, GR* grafo);
    GR* LerGrafo(char* nomeFicheiro);

    bool InserirCaminho(Adjacente** lista, int l, int c);
    Adjacente* ProcuraEmProfundidade(GR* grafo, Vertice* origem);
    bool dfs(Vertice* inicio, Vertice* origem, Adjacente** lista);

    Adjacente* ProcuraEmLargura(GR* grafo, Vertice* origem);

    bool ListarCaminhosRec(GR* grafo, Vertice* atual, Vertice* destino, Vertice* caminho[], int nivel);
    bool ListarTodosCaminhos(GR* grafo, Vertice* origem, Vertice* destino);

#pragma endregion