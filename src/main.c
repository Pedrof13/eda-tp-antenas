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

int main() {

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

    return 0;
}