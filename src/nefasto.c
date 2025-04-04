/**
 * @file nefasto.c
 * @author Pedro Sousa (a31514@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 02-04-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "../include/nefasto.h"

/**
 * @brief Função que calcula as coordenadas do efeito nefasto quando duas antenas estão alinhadas na horizontal
 * 
 * @param InicioNefasto Lista dos efeitos nefastos
 * @param a1 antena 1
 * @param a2 antena 2
 * @param matriz Dimensões da matriz
 * @return Elemento* 
 */
Elemento* CalcularHorizontal(Elemento *InicioNefasto, Elemento *a1, Elemento *a2, Tamanho *matriz) {

    //Calcular a distância
    int d = a2->c - a1->c;

    //Coordenadas do efeito nefasto 1
    int LinhaNefasto = a1->l;
    int ColunaNefasto = a1->c - d;

    Elemento *EfeitoNefasto;

    //Verificar se as coordenadas do efeito nefasto estão dentro dos limites da matriz
    if(LinhaNefasto < matriz->nLinhas && LinhaNefasto >= 0 
    && ColunaNefasto < matriz->nColunas && ColunaNefasto >= 0) 
    {
        EfeitoNefasto = CriaElemento('#',LinhaNefasto,ColunaNefasto);
        InicioNefasto = InsereOrdenado(InicioNefasto,EfeitoNefasto);
    }

    //Coordenadas do efeito nefasto 2
    LinhaNefasto = a2->l;
    ColunaNefasto = a2->c + d;

    //Verificar se as coordenadas do efeito nefasto estão dentro dos limites da matriz
    if(LinhaNefasto < matriz->nLinhas && LinhaNefasto >= 0 
    && ColunaNefasto < matriz->nColunas && ColunaNefasto >= 0) 
    {
        EfeitoNefasto = CriaElemento('#',LinhaNefasto,ColunaNefasto);
        InicioNefasto = InsereOrdenado(InicioNefasto,EfeitoNefasto);
    }

    return InicioNefasto;
}

/**
 * @brief Função que calcula as coordenadas do efeito nefasto quando duas antenas estão alinhadas na vertical
 * 
 * @param InicioNefasto Lista dos efeitos nefastos
 * @param a1 antena 1
 * @param a2 antena 2
 * @param matriz Dimensões da matriz
 * @return Elemento* 
 */
Elemento* CalcularVertical(Elemento *InicioNefasto, Elemento *a1, Elemento *a2, Tamanho *matriz) {

    //Calcular a distância
    int d = a2->l - a1->l;

    //Coordenadas do efeito nefasto 1
    int LinhaNefasto = a1->l - d;
    int ColunaNefasto = a1->c;

    Elemento *EfeitoNefasto;

    //Verificar se as coordenadas do efeito nefasto estão dentro dos limites da matriz
    if(LinhaNefasto < matriz->nLinhas && LinhaNefasto >= 0 
    && ColunaNefasto < matriz->nColunas && ColunaNefasto >= 0) 
    {
        EfeitoNefasto = CriaElemento('#',LinhaNefasto,ColunaNefasto);
        InicioNefasto = InsereOrdenado(InicioNefasto,EfeitoNefasto);
        //printf("Nefasto 1: (%d,%d)\n",LinhaNefasto,ColunaNefasto);
    }

    //Coordenadas do efeito nefasto 2
    LinhaNefasto = a2->l + d;
    ColunaNefasto = a2->c;

    //Verificar se as coordenadas do efeito nefasto estão dentro dos limites da matriz
    if(LinhaNefasto < matriz->nLinhas && LinhaNefasto >= 0 
    && ColunaNefasto < matriz->nColunas && ColunaNefasto >= 0) 
    {
        EfeitoNefasto = CriaElemento('#',LinhaNefasto,ColunaNefasto);
        InicioNefasto = InsereOrdenado(InicioNefasto,EfeitoNefasto);
        //printf("Nefasto 2: (%d,%d)\n",LinhaNefasto,ColunaNefasto);
    }

    return InicioNefasto;
}

/**
 * @brief Função que calcula efeito nefasto
 * 
 * @param InicioAntena Lista das antenas
 * @param InicioNefasto Lista dos efeitos nefastos
 * @param matriz Dimensões da matri<
 * @return Elemento* 
 */
Elemento* CalculoNefasto(Elemento *InicioAntena, Elemento *InicioNefasto, Tamanho* matriz) {

    //Verificar se a lista das antenas estiver vazia
    if(InicioAntena == NULL) return InicioNefasto;

    //auxiliares
    Elemento *atual = InicioAntena;
    Elemento *anterior = atual;

    bool acabou = false;

    while(acabou == false) {

        //Verificar se já acabou a lista
        if(anterior->p != NULL) {

            //Passar para a próxima posição
            if(atual->p != NULL) 
            {
                atual = atual->p;
            } 
            else
            {
                anterior = anterior->p;
                atual = anterior;
            }
        }
        //Caso contrário acaba
        else acabou = true;

        //Horizontal
        if(anterior->l == atual->l && anterior->c != atual->c && anterior != atual && anterior->tipo == atual->tipo)
        {
            InicioNefasto = CalcularHorizontal(InicioNefasto,anterior,atual,matriz);
        }

        //Vertical
        if(anterior->l != atual->l && anterior->c == atual->c && anterior != atual && anterior->tipo == atual->tipo)
        {
            InicioNefasto = CalcularVertical(InicioNefasto,anterior,atual,matriz);
        }

    }
    return InicioNefasto;
}

/*

Elemento* CalcularDiagonal(Elemento *inicio, Elemento *a1, Elemento *a2, Tamanho *matriz) {

    //Calcular a distância
    int d = a2->c - a1->c;

    //Coordenadas do efeito nefasto 1
    int LinhaNefasto = a1->l - d;
    int ColunaNefasto = a1->c -d;

    Elemento *EfeitoNefasto;

    //Verificar se as coordenadas do efeito nefasto estão dentro dos limites da matriz
    if(LinhaNefasto < matriz->nLinhas && LinhaNefasto >= 0 
    && ColunaNefasto < matriz->nColunas && ColunaNefasto >= 0) 
    {
        EfeitoNefasto = CriaElemento('#',LinhaNefasto,ColunaNefasto);
        inicio = InsereOrdenado(inicio,EfeitoNefasto);
        //printf("Nefasto 1: (%d,%d)\n",LinhaNefasto,ColunaNefasto);
    }

    //Coordenadas do efeito nefasto 2
    LinhaNefasto = a2->l + d;
    ColunaNefasto = a2->c + d;

    //Verificar se as coordenadas do efeito nefasto estão dentro dos limites da matriz
    if(LinhaNefasto < matriz->nLinhas && LinhaNefasto >= 0 
    && ColunaNefasto < matriz->nColunas && ColunaNefasto >= 0) 
    {
        EfeitoNefasto = CriaElemento('#',LinhaNefasto,ColunaNefasto);
        inicio = InsereOrdenado(inicio,EfeitoNefasto);
        //printf("Nefasto 2: (%d,%d)\n",LinhaNefasto,ColunaNefasto);
    }

    return inicio;

}
*/