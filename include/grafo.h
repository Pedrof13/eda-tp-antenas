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
        int destino;
        struct Adjacente* next;
    }Adjacente;

    Adjacente* CriarAdjacencia(int destino);

#pragma endregion


#pragma region VERTICES
    
    typedef struct Vertice {
        int id;
        char frequencia;
        int l,c;
        struct Vertice* proximo;
        struct Adjacente* next;
    }Vertice;

    typedef struct VerticeFile {
        int id;
        char frequencia;
        int l,c;
    }VerticeFile;

    Vertice* CriarVertice(int id, char f, int l, int c);
    Vertice* ProcurarVertice(Vertice* inicio, int id);
    Vertice* InserirVertice(Vertice* novo, Vertice* inicio);
    Vertice* RemoverVertice(Vertice* v, Vertice* inicio);

    bool InserirAdjacencia(Vertice* origem, Adjacente* novo);
    bool RemoverAdjacencia(Vertice* origem, Adjacente* adj);
    
#pragma endregion

#pragma region GRAFO
    
    typedef struct GR {
        int numVertices;
        Vertice* inicio;
    }GR;

    GR* CriarGrafo();
    bool GravarGrafo(char* nomeFicheiro, GR* grafo);
    GR* LerGrafo(char* nomeFicheiro);
    //gravar grafo em ficheiro binário
    //carregar grafo de ficheiro binário
    //Mostrar grafo
#pragma endregion