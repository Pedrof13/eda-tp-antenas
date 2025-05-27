/**
 * @file dados.h
 * @author Pedro Sousa (a31514@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 22-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/**
 * @brief Estrutura que representa um elemento da lista
 * 
 */
typedef struct Elemento {
    char tipo;//frequência da antena ou efeito nefasto
    int l,c;//coordenadas da matriz
    struct Elemento *p;//apontador para o próximo elemento da lista
}Elemento;

/**
 * @brief Estrutura que representa o tamanho da matriz
 * 
 */
typedef struct Tamanho {
    int nLinhas;
    int nColunas;
}Tamanho;

/**
 * @brief Estrutura usada nas funções de gravar e ler ficheiros
 * 
 */
typedef struct ElementoFile {
    char tipo;
    int l,c;
}ElementoFile;