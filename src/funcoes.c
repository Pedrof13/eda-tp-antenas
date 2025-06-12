/**
 * @file funcoes.c
 * @author Pedro Sousa (a31514@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 22-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../include/funcoes.h"

/**
 * @brief Função que cria um elemento
 *
 * @param tipo
 * @param l
 * @param c
 * @return Elemento*
 */
Elemento *CriaElemento(char tipo, int l, int c)
{
    Elemento *aux;

    aux = (Elemento *)malloc(sizeof(Elemento));
    if (aux != NULL)
    {
        aux->tipo = tipo;
        aux->l = l;
        aux->c = c;
        aux->p = NULL;
    }
    return aux;
}

/**
 * @brief Função que adiciona um elemento no início da lista
 *
 * @param inicio
 * @param novo
 * @return Elemento*
 */
Elemento *InsereInicio(Elemento *inicio, Elemento *novo)
{
    novo->p = inicio;
    inicio = novo;

    return inicio;
}

/**
 * @brief Função que adiciona um elemento no fim da lista
 *
 * @param inicio
 * @param novo
 * @return Elemento*
 */
Elemento *InsereFim(Elemento *inicio, Elemento *novo)
{
    Elemento *aux = inicio;

    // Percorrer até ao fim da lista
    while (aux->p != NULL)
    {
        aux = aux->p;
    }

    // inserir no fim
    aux->p = novo;

    return inicio;
}

/**
 * @brief Função que insere um elemento na lista de forma ordenada através das coordenadas
 *
 * @param inicio
 * @param novo
 * @return Elemento*
 */
Elemento *InsereOrdenado(Elemento *inicio, Elemento *novo)
{

    // Verificar se a lista está vazia ou e deve ser o primeiro da lista
    if (inicio == NULL || novo->l < inicio->l || (novo->l == inicio->l && novo->c < inicio->c))
    {
        inicio = InsereInicio(inicio, novo);
        return inicio;
    }

    // Verificar se já existe elemento com as mesmas coordenadas
    if (ProcurarElemento(inicio, novo->l, novo->c))
    {
        free(novo);
        return inicio;
    }

    Elemento *aux = inicio; // atual
    Elemento *aux2 = aux;   // anterior

    // Percorrer a lista até encontrar a posição correspondente
    while (aux->p != NULL &&
           (aux->l < novo->l || (aux->l == novo->l && aux->c < novo->c)))
    {
        aux2 = aux;
        aux = aux->p;
    }

    // Verificar se chegou no fim da lista
    if (aux->l < novo->l || (aux->l == novo->l && aux->c < novo->c))
    {
        inicio = InsereFim(inicio, novo);
    }
    else
    {
        // Insere o novo elemento entre dois elementos da lista
        aux2->p = novo;
        novo->p = aux;
    }

    return inicio;
}

/**
 * @brief Função que procura um elemento em específico na lista
 *
 * @param inicio
 * @param l
 * @param c
 * @return Elemento*
 */
Elemento *ProcurarElemento(Elemento *inicio, int l, int c)
{

    Elemento *aux = inicio;

    // Percorrer a lista
    while (aux != NULL && (aux->l < l || (aux->l == l && aux->c < c)))
    {
        aux = aux->p;
    }

    // Valor encontrado
    if (aux != NULL && aux->l == l && aux->c == c)
        return aux;

    // Caso contrário retorna NULL
    return NULL;
}

/**
 * @brief Função que remove um elemento em específico da lista
 *
 * @param inicio
 * @param l
 * @param c
 * @return Elemento*
 */
Elemento *RemoverElemento(Elemento *inicio, int l, int c)
{

    // Verificar se a lista está vazia ou se o elemento a ser removido não existe na lista
    if (inicio == NULL || !ProcurarElemento(inicio, l, c))
        return inicio;

    // Verificar se o elemento a ser removido é o primeiro da lista
    if (inicio->l == l && inicio->c == c)
    {
        Elemento *aux = inicio;
        inicio = inicio->p;
        free(aux);
        return inicio;
    }

    else
    {
        Elemento *aux = inicio; // atual
        Elemento *aux2 = aux;   // anterior

        // Procurar até encontrar
        while (aux != NULL && (aux->l != l && aux->c != c))
        {
            aux2 = aux;
            aux = aux->p;
        }

        // Caso tenha encontrado
        if (aux != NULL)
        {
            aux2->p = aux->p;
            free(aux);
        }
    }

    return inicio;
}

/**
 * @brief Função para mostrar a lista na consola em forma de matriz
 *
 * @param inicio
 * @return true
 * @return false
 */
bool ListarMatriz(Elemento *inicio, Tamanho *matriz)
{

    // Se a lista estiver vazia não mostra nada na consola
    if (inicio == NULL)
        return false;

    Elemento *aux = inicio;

    // Percorrer a "matriz"
    for (int l = 0; l < matriz->nLinhas; l = l + 1)
    {

        for (int c = 0; c < matriz->nColunas; c = c + 1)
        {

            if (aux->l == l && aux->c == c && aux != NULL)
            {
                // Mostra na consola
                printf("%c", aux->tipo);

                // Passa para o próximo elemento
                if (aux->p != NULL)
                    aux = aux->p;
            }
            else
            {
                printf(".");
            }
        }
        // Muda de linha
        printf("\n");
    }

    return true;
}

/**
 * @brief Função para gravar a lista num ficheiro txt em forma de matriz
 *
 * @param nomeFicheiro
 * @param inicio
 * @return true
 * @return false
 */
bool GravarElementoFicheiro(char *nomeFicheiro, Elemento *inicio, Tamanho *matriz)
{

    FILE *fp; // file point

    // Verificar se a lista está vazia
    if (inicio == NULL)
        return false;

    fp = fopen(nomeFicheiro, "wt");

    if (fp != NULL)
    {
        Elemento *aux = inicio;

        for (int l = 0; l < matriz->nLinhas; l = l + 1)
        {

            for (int c = 0; c < matriz->nColunas; c = c + 1)
            {
                if (aux->l == l && aux->c == c)
                {
                    fprintf(fp, "%c", aux->tipo);

                    // Passa para o próximo elemento
                    if (aux->p != NULL)
                        aux = aux->p;
                }
                else
                    fprintf(fp, ".");
            }

            fprintf(fp, "\n");
        }

        fclose(fp);
        return true;
    }
    else
        return false;
}

/**
 * @brief Função para ler um ficheiro txt, calcular a dimensão da matriz e guardar os elementos numa lista
 *
 * @param nomeFicheiro
 * @return Elemento*
 */
Elemento *LerElementosFicheiro(char *nomeFicheiro, Tamanho *matriz)
{

    FILE *fp; // file point

    fp = fopen(nomeFicheiro, "rt");

    if (fp != NULL)
    {
        Elemento *inicio = NULL;
        Elemento *aux;

        char c;
        bool PararContarColuna = false;

        int auxColunas = 0; // indica a coluna da matriz que está atualmente

        // equanto não chegar ao final do ficheiro
        while (!feof(fp))
        {

            c = fgetc(fp);
            if (c != '.' && c != '\n')
            {
                aux = CriaElemento(c, matriz->nLinhas, auxColunas);
                inicio = InsereOrdenado(inicio, aux);
            }
            if (c == '\n')
            {
                matriz->nLinhas++;
                auxColunas = -1;
                if (PararContarColuna == false)
                    PararContarColuna = true;
            }

            if (PararContarColuna == false)
                matriz->nColunas++;
            auxColunas++;
        }
        fclose(fp);
        return inicio;
    }
    else
    {
        return NULL;
    }
}

/**
 * @brief
 *
 * @param nomeFicheiro
 * @param inicio
 * @return true
 * @return false
 */
bool GravarBinario(char *nomeFicheiro, Elemento *inicio)
{

    FILE *fp;

    // Verificar se a lista está vazia
    if (inicio == NULL)
        return false;

    fp = fopen(nomeFicheiro, "wb");

    if (fp != NULL)
    {
        Elemento *aux = inicio;
        ElementoFile auxElemento;

        while (aux != NULL)
        {
            auxElemento.c = aux->c;
            auxElemento.l = aux->l;
            auxElemento.tipo = aux->tipo;

            fwrite(&auxElemento, sizeof(ElementoFile), 1, fp);
            aux = aux->p;
        }
        fclose(fp);
    }

    return true;
}

/**
 * @brief
 *
 * @param nomeFicheiro
 * @return Elemento*
 */
Elemento *LerBinario(char *nomeFicheiro)
{

    FILE *fp;
    Elemento *inicio = NULL;
    Elemento *aux;

    fp = fopen(nomeFicheiro, "rb");

    if (fp == NULL)
        return NULL;

    ElementoFile auxElemento;
    while (fread(&auxElemento, sizeof(ElementoFile), 1, fp))
    {

        aux = CriaElemento(auxElemento.tipo, auxElemento.l, auxElemento.c);
        inicio = InsereOrdenado(inicio, aux);
    }
    fclose(fp);
    return inicio;
}

/**
 * @brief Função que destroi a lista
 *
 * @param inicio
 * @return Elemento*
 */
Elemento *DestroiLista(Elemento *inicio)
{

    // Verificar se a lista não está vazia
    if (inicio != NULL)
    {
        Elemento *aux;

        while (inicio != NULL)
        {
            aux = inicio;
            inicio = inicio->p;
            free(aux);
        }
    }

    return inicio;
}