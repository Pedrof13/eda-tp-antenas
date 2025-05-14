/**
 * @file grafo.c
 * @author Pedro Sousa (a31514@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 14-05-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../include/grafo.h"

/**
 * @brief Função para criar vertice
 * 
 * @param f 
 * @param l 
 * @param c 
 * @return Vertice* 
 */
Vertice* CriarVertice(int id, char f, int l, int c) {
    Vertice* aux;

    aux = (Vertice*)malloc(sizeof(Vertice));

    if(aux!=NULL) {
        aux->id = id;
        aux->frequencia = f;
        aux->l = l;
        aux->c = c;
        aux->next = NULL;
        aux->proximo = NULL;
    }

    return aux;
}

/**
 * @brief Função para procurar um vertice existente
 * 
 * @param inicio 
 * @param l 
 * @param c 
 * @return Vertice* 
 */
Vertice* ProcurarVertice(Vertice* inicio, int l, int c) {

    Vertice* aux = inicio;

    //Percorrer a lista
    while(aux != NULL && (aux->l < l || (aux->l == l && aux->c < c)))
    {
        aux = aux->proximo;
    }

    //Vertice encontrado
    if(aux != NULL && aux->l == l && aux->c == c) return aux;

    //Vertice não encontrado
    return NULL;

}

/**
 * @brief Função para inserir um vertice na lista
 * 
 * @param novo 
 * @param inicio 
 * @return Vertice* 
 */
Vertice* InserirVertice(Vertice* novo, Vertice* inicio) {

    //Verificar se o vertice pretence ao inicio da lista
    if(inicio == NULL || novo->l < inicio->l || (novo->l == inicio->l && novo->c < inicio->c))
    {
        novo->proximo = inicio;
        inicio = novo;
        return inicio;
    }

    //Verificar se já existe um Vertice com as mesmas coordenadas
    if(ProcurarVertice(inicio,novo->l,novo->c) != NULL) 
    {
        free(novo);
        return inicio;
    }

    Vertice* atual = inicio;
    Vertice* anterior = atual;

    //Percorrer a lista até encontrar a posição correspondente
    while(atual->proximo != NULL &&
    atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c)) 
    {
        anterior = atual;
        atual = atual->proximo;
    }

    //Verificar se chegou ao fim
    if(atual->proximo == NULL)
    {
        //Insere no fim
        atual->proximo = novo;
    }
    else
    {
        //Insere o novo vertice entre dois vertices da lista
        anterior->proximo = novo;
        novo->proximo = atual;
    }

    return inicio;
}

/**
 * @brief Função para remover o vertice da lista
 * 
 * @param v 
 * @param inicio 
 * @return Vertice* 
 */
Vertice* RemoverVertice(Vertice* v, Vertice* inicio) {
    
    //Verificar se a lista está vaiza ou se o vertice a ser removido não existe na lista
    if(inicio == NULL || ProcurarVertice(inicio,v->l,v->c) == NULL) return inicio;


    //Verificar se o vértice a ser removido é o primeiro da lista
    if(v->l == inicio->l && v->c == inicio->c) 
    {
        Vertice* aux = inicio;
        inicio = inicio->proximo;
        free(aux);
        return inicio;
    }
    else
    {
        Vertice* atual = inicio;
        Vertice* anterior = atual;

        //Procurar até encontrar
        while(atual != NULL && atual->l != v->l && atual->c != v->c)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual != NULL) {
            anterior->proximo = atual->proximo;
            free(atual);
        }
        return inicio;
    }
    
}