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

int main()
{

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

    // Fase 2

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

        a1 = CriarVertice('A',0,1);
        grafo->inicio = InserirVertice(a1,grafo->inicio);

        a2 = CriarVertice('A',1,1);
        grafo->inicio = InserirVertice(a2,grafo->inicio);

        a3 = CriarVertice('B',1,3);
        grafo->inicio = InserirVertice(a3,grafo->inicio);

        a4 = CriarVertice('A',2,1);
        grafo->inicio = InserirVertice(a4,grafo->inicio);

        a5 = CriarVertice('B',3,3);
        grafo->inicio = InserirVertice(a5,grafo->inicio);


        //Criar as adjacencias
        Adjacente* adj;
        bool ok;

        adj = CriarAdjacencia(1,1);
        ok = InserirAdjacencia(a1,adj);

        adj = CriarAdjacencia(2,1);
        ok = InserirAdjacencia(a1,adj);

        adj = CriarAdjacencia(0,1);
        ok = InserirAdjacencia(a2,adj);

        adj = CriarAdjacencia(2,1);
        ok = InserirAdjacencia(a2,adj);

        adj = CriarAdjacencia(3,3);
        ok = InserirAdjacencia(a3,adj);

        adj = CriarAdjacencia(0,1);
        ok = InserirAdjacencia(a4,adj);

        adj = CriarAdjacencia(1,1);
        ok = InserirAdjacencia(a4,adj);

        adj = CriarAdjacencia(1,3);
        ok = InserirAdjacencia(a5,adj);

        ok = GravarGrafo("grafo.bin", grafo);

    #pragma endregion

    */

    // Ler um grafo a partir de um ficheiro binário
    GR *grafo = LerGrafo("grafo.bin");

    Vertice *a2 = ProcurarVertice(grafo->inicio, 1, 1);
    Vertice *a4 = ProcurarVertice(grafo->inicio, 2, 1);

    // bool ok = RemoverVertice(a4,&grafo->inicio);

    // Adjacente* adj = CriarAdjacencia(0,1);
    // bool ok = RemoverAdjacencia(a2,adj);

    // Adjacente* lista = ProcuraEmProfundidade(grafo, a2);
    // Adjacente* lista = ProcuraEmProfundidade(grafo,a2);
    ListarTodosCaminhos(grafo, a2, a4);

    return 0;
}