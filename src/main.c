/**
 * @file main.c
 * @author Pedro Sousa (a31514@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 22-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../include/nefasto.h"
#include "../include/grafo.h"

int main() {
/* 
#pragma region Declarar variaveis
    //Criar uma lista para as antenas
    Elemento *InicioAntena = NULL;

    //Criae outra lista para os efeitos nefastos
    Elemento *InicioNefasto = NULL;

    Tamanho *matriz;
    
    //Atribuir uma dimanesão à matriz
    matriz->nLinhas = 0;
    matriz->nColunas = 0;

    Elemento *novo;

#pragma endregion

    InicioAntena = LerElementosFicheiro("antenas.txt", matriz);

    InicioNefasto = CalculoNefasto(InicioAntena,InicioNefasto,matriz);

#pragma region Mostrar matriz
    //Lista antena
    bool mostra = ListarMatriz(InicioAntena,matriz);

    printf("\n\n");

    //Lista nefasto
    mostra = ListarMatriz(InicioNefasto,matriz);

#pragma endregion

#pragma region Modificar listas
    //Remover antena
    InicioAntena = RemoverElemento(InicioAntena,1,2);
    //InicioAntena = RemoverElemento(InicioAntena,2,2);

    novo = CriaElemento('B',4,1);
    InicioAntena = InsereOrdenado(InicioAntena,novo);

    novo = CriaElemento('B',4,2);
    InicioAntena = InsereOrdenado(InicioAntena,novo);

    InicioNefasto = DestroiLista(InicioNefasto);

    InicioNefasto = CalculoNefasto(InicioAntena,InicioNefasto,matriz);

#pragma endregion

    printf("\n\n");

#pragma region Mostrar
    //Lista antena
    mostra = ListarMatriz(InicioAntena,matriz);

    printf("\n\n");

    //Lista nefasto
    mostra = ListarMatriz(InicioNefasto,matriz);
#pragma endregion
*/

/*
//Criar um grafo
GR* grafo = CriarGrafo();

//Criar as antenas
Vertice* a1;
Vertice* a2;
Vertice* a3;

#pragma region ManipularVertices

a1 = CriarVertice(1,'B',0,2);
grafo->inicio = InserirVertice(a1,grafo->inicio);
grafo->numVertices = grafo->numVertices + 1;

a2 = CriarVertice(2,'A',1,3);
grafo->inicio = InserirVertice(a2,grafo->inicio);
grafo->numVertices = grafo->numVertices + 1;

a3 = CriarVertice(3,'A',1,2);
grafo->inicio = InserirVertice(a3,grafo->inicio);
grafo->numVertices = grafo->numVertices + 1;

#pragma endregion


Adjacente* adj;
adj = CriarAdjacencia(2);
bool ok = InserirAdjacencia(a3,adj);

adj = CriarAdjacencia(3); 
ok = InserirAdjacencia(a2,adj);

ok = RemoverAdjacencia(a2,adj);

ok = GravarGrafo("grafo.bin", grafo);
*/


GR* grafo = LerGrafo("grafo.bin");


    return 0;
}