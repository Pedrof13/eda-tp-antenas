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
    
    //Criar um elemento para a lista
    Elemento *e1 = CriaElemento('A',1,2);

    //Inserir o elemento criado para a lista
    inicio = InsereOrdenado(inicio,e1);

    e1 = CriaElemento('A',4,4);

    inicio = InsereOrdenado(inicio,e1);

#pragma endregion

#pragma region Remover

    inicio = RemoverElemento(inicio,4,4);

#pragma endregion

#pragma region Mostar

    bool mostrarLista = ListarMatriz(inicio);

#pragma endregion

    return 0;
}