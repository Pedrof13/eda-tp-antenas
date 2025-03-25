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

#include "funcoes.h"

/**
 * @brief 
 * 
 * @param tipo 
 * @param l 
 * @param c 
 * @return Elemento* 
 */
Elemento *CriaElemento(char tipo, int l, int c) {
	Elemento* aux;

	aux = (Elemento*)malloc(sizeof(Elemento));
	if (aux!=NULL) {
		aux->tipo = tipo;
        aux->l = l;
        aux->c = c;
		aux->p = NULL;
	}
	return aux;
}

/**
 * @brief 
 * 
 * @param inicio 
 * @param novo 
 * @return Elemento* 
 */
Elemento *InsereInicio(Elemento *inicio, Elemento *novo) {
    novo->p = inicio;
    inicio = novo;

    return inicio;
}

/**
 * @brief 
 * 
 * @param inicio 
 * @param novo 
 * @return Elemento* 
 */
Elemento *InsereFim(Elemento *inicio, Elemento *novo) {
    Elemento *aux = inicio;

    //Percorrer até ao fim da lista
    while(aux->p != NULL) {
        aux = aux->p;
    }

    //inserir no fim
    aux->p = novo;

    return inicio;
}

/**
 * @brief 
 * 
 * @param inicio 
 * @param novo 
 * @return Elemento* 
 */
Elemento *InsereOrdenado(Elemento *inicio, Elemento *novo) {

    //Verificar se a lista está vazia ou e deve ser o primeiro da lista 
    if(inicio == NULL || novo->l < inicio->l || (novo->l == inicio->l && novo->c < inicio->c)) 
    {
        inicio = InsereInicio(inicio,novo);
        return inicio;
    }

    //Verificar se já existe elemento com as mesmas coordenadas
    if(ProcurarElemento(inicio,novo->l,novo->c)) 
    {
        free(novo);
        return inicio;
    }

    Elemento *aux = inicio; //atual
    Elemento *aux2 = aux; //anterior

    //Percorrer a lista até encontrar a posição correspondente
    while(aux->p !=NULL && 
    (aux->l < novo->l || (aux->l == novo->l && aux->c < novo->c))) 
    {
        aux2 = aux;
        aux = aux->p;
    }

    //Verificar se chegou no fim da lista
    if(aux->p == NULL) 
    {
        inicio = InsereFim(inicio,novo);

    } else {
        //Insere o novo elemento entre dois elementos da lista
        aux2->p = novo;
        novo->p = aux;
    }

    return inicio;
}

/**
 * @brief 
 * 
 * @param inicio 
 * @param l 
 * @param c 
 * @return Elemento* 
 */
Elemento *ProcurarElemento(Elemento *inicio, int l, int c) {

    Elemento *aux = inicio;

    //Percorrer a lista
    while(aux != NULL && (aux->l < l || (aux->l == l && aux->c < c))) 
    {
        aux = aux->p;
    }
    
    //Valor encontrado
    if(aux != NULL && aux->l ==l && aux->c == c) return aux;

    //Caso contrário retorna NULL
    return NULL;

}

/**
 * @brief 
 * 
 * @param inicio 
 * @param l 
 * @param c 
 * @return Elemento* 
 */
Elemento *RemoverElemento(Elemento *inicio, int l, int c) {

    //Verificar se a lista está vazia ou se o elemento a ser removido não existe na lista
    if(inicio == NULL || !ProcurarElemento(inicio,l,c)) return inicio;

    
    //Verificar se o elemento a ser removido é o primeiro da lista
    if(inicio->l == l && inicio->c == c) 
    {
        Elemento *aux = inicio;
        inicio = inicio->p;
        free(aux);
        return inicio;
    }

    else 
    {
        Elemento *aux = inicio; //atual
        Elemento *aux2 = aux; //anterior

        //Procurar até encontrar
        while (aux!=NULL && (aux->l != l && aux->c != c))
        {
            aux2 = aux;
            aux = aux->p;
        }

        //Caso tenha encontrado
        if(aux !=NULL) {
            aux2->p = aux->p;
            free(aux);
        }
        
    }

    return inicio;
}


bool ListarMatriz(Elemento *inicio) {

    //Se a lista estiver vazia não mostra nada na consola
    if(inicio == NULL) return false;
    
    Elemento *aux = inicio;

    //Percorrer a "matriz"
    for(int l=0; l < LINHA; l=l+1) {

        for(int c=0; c < COLUNA; c=c+1) {

            if(aux->l == l && aux->c == c && aux != NULL) 
            {
                //Mostra na consola
                printf("%c", aux->tipo);

                //Passa para o próximo elemento
                if(aux->p !=NULL) aux = aux->p;
            }
            else {
                printf(".");
            }
        }
        //Muda de linha
        printf("\n");
    }

    return true;
}