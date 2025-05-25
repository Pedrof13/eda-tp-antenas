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
 * @brief Função para criar uma adjacência
 *
 * @param l linha
 * @param c coluna
 * @return Adjacente*
 */
Adjacente *CriarAdjacencia(int l, int c)
{

    Adjacente *aux;
    aux = (Adjacente *)malloc(sizeof(Adjacente));

    if (aux != NULL)
    {
        aux->l = l;
        aux->c = c;
        aux->next = NULL;
    }
    return aux;
}

/**
 * @brief Função para inserir adjacência à lista por ordem das coordenadas
 *
 * @param origem vertice origem
 * @param novo nova adjacência
 * @return true
 * @return false
 */
bool InserirAdjacencia(Vertice *origem, Adjacente *novo)
{

    // Verificar se o vertice pretence ao inicio da lista
    if (origem->next == NULL || novo->l < origem->next->l || (novo->l == origem->next->l && novo->c < origem->next->c))
    {
        novo->next = origem->next;
        origem->next = novo;
        return true;
    }

    Adjacente *atual = origem->next;
    Adjacente *anterior = atual;

    // Percorrer a lista até encontrar a posição correspondente
    while (atual != NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c)))
    {
        // Verificar se o próximo da lista é nulo
        if (atual->next != NULL)
        {
            anterior = atual;
            atual = atual->next;
        }
        else
            break; // Parou o while
    }

    if (atual->next == NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c)))
    {
        // Insere no fim
        atual->next = novo;
    }
    else
    {
        // Insere o novo vertice entre dois vertices da lista
        anterior->next = novo;
        novo->next = atual;
    }

    return true; // Sucesso
}

/**
 * @brief Função para remover uma adjacência
 *
 * @param origem vertice origem
 * @param adj adjacencia a ser removida
 * @return true
 * @return false
 */
bool RemoverAdjacencia(Vertice *origem, Adjacente *adj)
{

    // Verificar se o Vertice origem é nulo ou se a lista de adjacência está vazia
    if (origem == NULL || origem->next == NULL)
        return false; // Falhou

    // Verificar se a adjacência é o primeiro da lista
    if (origem->next->l == adj->l || (origem->next->l == adj->l && origem->next->c == adj->c))
    {
        Adjacente *aux = origem->next;

        // Verificar se adjacência é o único da lista
        if (origem->next->next == NULL)
        {
            origem->next = NULL;
        }
        else
        {
            origem->next = origem->next->next;
        }
        free(aux);
        return true;
    }

    Adjacente *atual = origem->next;
    Adjacente *anterior = atual;

    // Percorrer a lista de adjacências
    while (atual->l != adj->l || (atual->l == adj->l && atual->c != adj->c))
    {

        if (atual->next != NULL)
        {
            anterior = atual;
            atual = atual->next;
        }
        else
            break;
    }

    // Verificar se encontrou a adjacência a ser removida
    if (atual->l == adj->l && atual->c == adj->c)
    {

        if (atual->next != NULL)
        {
            anterior->next = atual->next;
        }
        else
        {
            anterior->next = NULL;
        }
        free(atual);
        return true;
    }

    return false;
}

/**
 * @brief Função para criar vertice
 *
 * @param f frequência
 * @param l linha
 * @param c coluna
 * @return Vertice*
 */
Vertice *CriarVertice(char f, int l, int c)
{

    Vertice *aux;
    aux = (Vertice *)malloc(sizeof(Vertice));

    if (aux != NULL)
    {
        aux->f = f;
        aux->l = l;
        aux->c = c;
        aux->visitado = false;
        aux->next = NULL;
        aux->proximo = NULL;
    }
    return aux;
}

/**
 * @brief Função para procurar vertice a partir das coordenadas
 *
 * @param inicio lista de vertices
 * @param l linha
 * @param c coluna
 * @return Vertice*
 */
Vertice *ProcurarVertice(Vertice *inicio, int l, int c)
{

    Vertice *aux = inicio;

    // Percorrer a lista
    while (aux != NULL &&
           (aux->l != l || (aux->l == l && aux->c != c)))
    {
        if (aux->proximo != NULL)
            aux = aux->proximo;
        else
            break;
    }

    // Vertice encontrado
    if (aux != NULL && aux->l == l && aux->c == c)
        return aux;

    // Vertice não encontrado
    return NULL;
}

/**
 * @brief Função para inserir um vertice na lista
 *
 * @param novo novo vertice
 * @param inicio lista de vertices
 * @return Vertice*
 */
bool InserirVertice(Vertice *novo, Vertice **inicio)
{

    // Verificar se já existe um Vertice com as mesmas coordenadas
    if (ProcurarVertice(*inicio, novo->l, novo->c) != NULL)
    {
        free(novo);
        return false;
    }

    // Verificar se o vertice pretence ao inicio da lista
    if (*inicio == NULL || novo->l < (*inicio)->l || (novo->l == (*inicio)->l && novo->c < (*inicio)->c))
    {
        novo->proximo = *inicio;
        *inicio = novo;
        return true;
    }

    Vertice *atual = (*inicio);
    Vertice *anterior = atual;

    // Percorrer a lista até encontrar a posição correspondente
    while (atual != NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c)))
    {
        // Verificar se o próximo da lista é nulo
        if (atual->proximo != NULL)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        else
            break; // Parou o while
    }

    if (atual->proximo == NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c)))
    {
        // Insere no fim
        atual->proximo = novo;
    }
    else
    {
        // Insere o novo vertice entre dois vertices da lista
        anterior->proximo = novo;
        novo->proximo = atual;
    }

    return true;
}

/**
 * @brief Função para remover o vertice da lista
 *
 * @param v vertice a ser removido
 * @param inicio lista de vertices
 * @return Vertice*
 */
bool RemoverVertice(Vertice *v, Vertice **inicio)
{

    // Verificar se a lista está vaiza ou se o vertice a ser removido não existe na lista
    if (*inicio == NULL || ProcurarVertice(*inicio, v->l, v->c) == NULL)
        return false;

    // Verificar se o vértice a ser removido é o primeiro da lista
    if (v->l == (*inicio)->l && v->c == (*inicio)->c)
    {
        Vertice *aux = *inicio;
        Adjacente *auxAdj = aux->next;
        Adjacente *Remover = CriarAdjacencia(v->l, v->c);

        // Procurar outros vertices para remover adjacência do vertice a ser removido
        while (auxAdj != NULL)
        {

            if (ProcurarVertice(*inicio, auxAdj->l, auxAdj->c) != NULL)
            {
                Vertice *VerticeAdjacente = ProcurarVertice(*inicio, auxAdj->l, auxAdj->c);
                bool ok = RemoverAdjacencia(VerticeAdjacente, Remover);
            }

            if (auxAdj->next != NULL)
                auxAdj = auxAdj->next;
            else
                break;
        }

        *inicio = (*inicio)->proximo;
        free(aux);
        return true;
    }
    else
    {
        Vertice *atual = *inicio;
        Vertice *anterior = atual;

        // Procurar até encontrar
        while (atual != NULL && (atual->l != v->l || (atual->l == v->l && atual->c != v->c)))
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual != NULL)
        {

            Adjacente *auxAdj = atual->next;
            Adjacente *Remover = CriarAdjacencia(v->l, v->c);

            // Procurar outros vertices para remover adjacência do vertice a ser removido
            while (auxAdj != NULL)
            {
                if (ProcurarVertice(*inicio, auxAdj->l, auxAdj->c) != NULL)
                {
                    Vertice *VerticeAdjacente = ProcurarVertice(*inicio, auxAdj->l, auxAdj->c);
                    bool ok = RemoverAdjacencia(VerticeAdjacente, Remover);
                }

                if (auxAdj->next != NULL)
                    auxAdj = auxAdj->next;
                else
                    break;
            }

            anterior->proximo = atual->proximo;
            free(atual);
        }
        return true;
    }
}

/**
 * @brief Função para criar um grafo
 *
 * @param numVertices
 * @return GR*
 */
GR *CriarGrafo(int numVertices)
{

    GR *grafo;
    grafo = (GR *)malloc(sizeof(GR));

    if (grafo != NULL)
    {
        grafo->numVertices = numVertices;
        grafo->inicio = NULL;
    }

    return grafo;
}

/**
 * @brief Função para gravar um grafo em fichiero binário
 *
 * @param nomeFicheiro
 * @param grafo
 * @return true
 * @return false
 */
bool GravarGrafo(char *nomeFicheiro, GR *grafo)
{

    FILE *fp = fopen(nomeFicheiro, "wb");

    // Verificar se há erro ao abrir o ficheiro ou a lista está vazia
    if (fp == NULL || grafo->inicio == NULL)
        return false;

    // gravar o número de vertices
    fwrite(&grafo->numVertices, sizeof(int), 1, fp);

    // Gravar Vértices e adjacências
    Vertice *aux = grafo->inicio;

    Adjacente *Adj = NULL;
    int numAdj = 0;

    while (aux != NULL)
    {
        fwrite(&aux->f, sizeof(char), 1, fp);
        fwrite(&aux->l, sizeof(int), 1, fp);
        fwrite(&aux->c, sizeof(int), 1, fp);

        // gravar id do vertice destino
        Adj = aux->next;

        // número de adjacências
        numAdj = 0;

        while (Adj != NULL)
        {
            numAdj = numAdj + 1;
            Adj = Adj->next;
        }
        fwrite(&numAdj, sizeof(int), 1, fp);
        Adj = aux->next;

        while (Adj != NULL)
        {
            fwrite(&Adj->l, sizeof(int), 1, fp);
            fwrite(&Adj->c, sizeof(int), 1, fp);

            if (Adj->next != NULL)
                Adj = Adj->next;
            else
                break;
        }

        aux = aux->proximo;
    }

    fclose(fp);
    return true;
}

/**
 * @brief Função para ler um grafo em ficheiro binário
 *
 * @param nomeFicheiro
 * @return GR*
 */
GR *LerGrafo(char *nomeFicheiro)
{
    FILE *fp = fopen(nomeFicheiro, "rb");

    if (fp == NULL)
        return NULL;

    int numVertices;

    fread(&numVertices, sizeof(int), 1, fp);

    // Criar um grafo
    GR *grafo = CriarGrafo(numVertices);

    Vertice *aux;
    Adjacente *Adj = NULL;
    int numAdj = 0;
    bool ok = false;
    // Percorrer os vertices
    for (int i = 0; i < grafo->numVertices; i = i + 1)
    {

        int l, c;
        char f;

        // Ler Vertice
        fread(&f, sizeof(char), 1, fp);
        fread(&l, sizeof(int), 1, fp);
        fread(&c, sizeof(int), 1, fp);

        // Criar Vertice
        aux = CriarVertice(f, l, c);

        // Inserir Vertice na lista
        ok = InserirVertice(aux, &grafo->inicio);

        // número de adjacências
        int numAdj = 0;
        Adj = aux->next;
        bool feedback = false;

        fread(&numAdj, sizeof(int), 1, fp);

        for (int j = 0; j < numAdj; j = j + 1)
        {
            int linha, coluna;
            fread(&linha, sizeof(int), 1, fp);
            fread(&coluna, sizeof(int), 1, fp);
            Adj = CriarAdjacencia(linha, coluna);
            feedback = InserirAdjacencia(aux, Adj);
        }
    }

    fclose(fp);
    return grafo;
}

bool InserirCaminho(Adjacente **lista, int l, int c)
{

    Adjacente *novo = CriarAdjacencia(l, c);

    // Insere no inicio da lista
    if (*lista == NULL)
    {
        *lista = novo;
    }

    // Inserir no fim da lista
    else
    {
        Adjacente *aux = *lista;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = novo;
    }

    return true;
}
/**
 * @brief Função que procura em profundidade a partir de uma determinada antena
 *
 * @param grafo
 * @param origem vertice origem
 * @return true
 * @return false
 */
Adjacente *ProcuraEmProfundidade(GR *grafo, Vertice *origem)
{

    if (grafo == NULL || origem == NULL)
        return NULL;

    // Inicializar todos como false
    Vertice *aux = origem->proximo;

    while (aux->proximo != NULL)
    {
        aux->visitado = false;
        aux = aux->proximo;
    }

    Adjacente *lista = NULL;
    dfs(grafo->inicio, origem, &lista);
    return lista;
}

/**
 * @brief Função recursiva que faz a procura em profundidade (DFS)
 *
 * @param inicio lista de vertices
 * @param origem vertice de origem
 * @return true
 * @return false
 */
bool dfs(Vertice *inicio, Vertice *origem, Adjacente **lista)
{

    if (origem == NULL || origem->visitado == true)
        return false;

    origem->visitado = true;

    bool ok = InserirCaminho(lista, origem->l, origem->c);

    Adjacente *adj = origem->next;
    while (adj != NULL)
    {
        Vertice *proximo = ProcurarVertice(inicio, adj->l, adj->c);
        dfs(inicio, proximo, lista);
        adj = adj->next;
    }

    return true;
}

/**
 * @brief Procura em largura a partir de uma determinada antena (BFS)
 *
 * @param grafo
 * @param origem vertice de origem
 * @return true
 * @return false
 */
Adjacente *ProcuraEmLargura(GR *grafo, Vertice *origem)
{

    // Verificar se o grafo e vertice são nulos
    if (grafo == NULL || origem == NULL)
        return NULL;

    // Inicializar todos como false
    Vertice *aux = origem->proximo;

    while (aux->proximo != NULL)
    {
        aux->visitado = false;
        aux = aux->proximo;
    }
    Adjacente *lista = NULL;

    Vertice *fila[grafo->numVertices];
    int frente = 0, tras = 0;

    origem->visitado = true;
    fila[tras++] = origem;
    // printf("Antenas alcançadas a partir da antena %c (%d,%d): \n", origem->f, origem->l, origem->c);
    while (frente < tras)
    {
        Vertice *atual = fila[frente++];
        InserirCaminho(&lista, atual->l, atual->c);

        // printf("Antena %c (%d,%d)\n", atual->f, atual->l, atual->c);

        Adjacente *adj = atual->next;
        while (adj != NULL)
        {

            // Procurar o vertice correspondente ao ID
            Vertice *vizinho = grafo->inicio;
            while (vizinho != NULL && (vizinho->l != adj->l || (vizinho->l == adj->l && vizinho->c != adj->c)))
            {
                vizinho = vizinho->proximo;
            }

            if (vizinho != NULL && vizinho->visitado == false)
            {
                vizinho->visitado = true;
                fila[tras++] = vizinho;
            }

            adj = adj->next;
        }
    }

    return lista;
}

/**
 * @brief Função auxiliar para listar todos os caminhos possíveis entre duas antenas (Recursiva)
 *
 * @param grafo
 * @param atual
 * @param destino
 * @param caminho
 * @param nivel
 * @return true
 * @return false
 */
bool ListarCaminhosRec(GR *grafo, Vertice *atual, Vertice *destino, Vertice *caminho[], int nivel)
{

    if (grafo == NULL || atual == NULL || destino == NULL)
        return false;

    atual->visitado = true;
    caminho[nivel++] = atual;

    if (atual == destino)
    {
        printf("Caminho:");
        for (int i = 0; i < nivel; i = i + 1)
        {
            Vertice *v = caminho[i];
            printf("(%d,%d)", v->l, v->c);
            if (i < nivel - 1)
                printf("->");
        }
        printf("\n");
    }
    else
    {
        // Percorrer a lista de adjacências
        Adjacente *a = atual->next;
        while (a != NULL)
        {
            Vertice *v = ProcurarVertice(grafo->inicio, a->l, a->c);
            if (v != NULL && v->visitado == false && v->f == atual->f)
            {
                ListarCaminhosRec(grafo, v, destino, caminho, nivel);
            }
            if (a->next != NULL)
                a = a->next;
            else
                break;
        }
    }

    atual->visitado = false;
    return true;
}

/**
 * @brief Função para listar todos os caminhos possíveis entre duas antenas
 *
 * @param grafo
 * @param origem
 * @param destino
 * @return true
 * @return false
 */
bool ListarTodosCaminhos(GR *grafo, Vertice *origem, Vertice *destino)
{

    if (grafo == NULL || origem == NULL || destino == NULL)
        return false;

    // Inicializar todos como false
    Vertice *aux = origem->proximo;
    while (aux->proximo != NULL)
    {
        aux->visitado = false;
        aux = aux->proximo;
    }

    Vertice *caminho[grafo->numVertices];
    bool ok = ListarCaminhosRec(grafo, origem, destino, caminho, 0);

    return true;
}