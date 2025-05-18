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


//Fase 2

/*
#pragma region GRAFO

    //Cria um grafo
    GR* grafo = CriarGrafo(5);

    //Antena
    Vertice* a1;
    Vertice* a2;
    Vertice* a3;
    Vertice* a4;
    Vertice* a5;

    a1 = CriarVertice(1,'A',0,1);
    grafo->inicio = InserirVertice(a1,grafo->inicio);

    a2 = CriarVertice(2,'A',1,1);
    grafo->inicio = InserirVertice(a2,grafo->inicio);

    a3 = CriarVertice(3,'B',1,3);
    grafo->inicio = InserirVertice(a3,grafo->inicio);

    a4 = CriarVertice(4,'A',2,1);
    grafo->inicio = InserirVertice(a4,grafo->inicio);

    a5 = CriarVertice(5,'B',3,3);
    grafo->inicio = InserirVertice(a5,grafo->inicio);


    //Criar as adjacencias
    Adjacente* adj;
    bool ok;

    adj = CriarAdjacencia(2);
    ok = InserirAdjacencia(a1,adj);

    adj = CriarAdjacencia(4);
    ok = InserirAdjacencia(a1,adj);

    adj = CriarAdjacencia(1);
    ok = InserirAdjacencia(a2,adj);

    adj = CriarAdjacencia(4);
    ok = InserirAdjacencia(a2,adj);

    adj = CriarAdjacencia(5);
    ok = InserirAdjacencia(a3,adj);

    adj = CriarAdjacencia(1);
    ok = InserirAdjacencia(a4,adj);

    adj = CriarAdjacencia(2);
    ok = InserirAdjacencia(a4,adj);

    adj = CriarAdjacencia(3);
    ok = InserirAdjacencia(a5,adj);

    ok = GravarGrafo("grafo.bin", grafo);

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

//ool ok = ProcuraEmProfundidade(grafo, 1);

Vertice* a2 = ProcurarVertice(grafo->inicio,2);
//bool ok=ProcuraEmLargura(grafo,a2);
Vertice* a3 = ProcurarVertice(grafo->inicio,3);

bool ok = ListarTodosCaminhos(grafo,a2,a3);

//bool ok = ProcuraEmLargura(grafo,a2);

    return 0;
}