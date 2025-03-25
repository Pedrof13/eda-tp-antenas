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

#include "funcoes.h"

int main() {

#pragma region Criar 
    //Criar uma lista
    Elemento *inicio = NULL;

    inicio = LerElementosFicheiro("antenas.txt");
    bool mostrarLista = ListarMatriz(inicio);

    /*
    //Criar um elemento para a lista
    Elemento *antena = CriaElemento('A',1,2);

    //Inserir o elemento criado para a lista
    inicio = InsereOrdenado(inicio,antena);

    antena = CriaElemento('A',4,4);
    inicio = InsereOrdenado(inicio,antena);

    antena = CriaElemento('B',2,1);
    inicio = InsereOrdenado(inicio,antena);
    */

#pragma endregion
/*
#pragma region Remover

    inicio = RemoverElemento(inicio,4,4);

#pragma endregion

#pragma region Mostar

    bool mostrarLista = ListarMatriz(inicio);

#pragma endregion

    bool gravar = GravarElementoFicheiro("antenas.txt", inicio);
*/
    return 0;
}