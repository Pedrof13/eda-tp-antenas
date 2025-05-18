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
 * @brief Função para criar adjacencia
 * 
 * @param destino 
 * @return Adjacente* 
 */
Adjacente* CriarAdjacencia(int destino) {
    Adjacente* aux;
    
    aux = (Adjacente*)malloc(sizeof(Adjacente));

    if(aux!=NULL) {
        aux->destino = destino;
        aux->next = NULL;
    }
    return aux;
}

/**
 * @brief Função para inserir uma adjacencia
 * 
 * @param origem 
 * @param novo 
 * @return true 
 * @return false 
 */
bool InserirAdjacencia(Vertice* origem, Adjacente* novo) {

    if(novo!=NULL) {
        novo->next = origem->next;
        origem->next = novo;

        return true; //Sucesso
    }

    return false;//Falhou
}

/**
 * @brief Função para remover uma adjacência
 * 
 * @param origem 
 * @param adj 
 * @return true 
 * @return false 
 */
bool RemoverAdjacencia(Vertice* origem, Adjacente* adj) {

    //Verificar se o Vertice origem é nulo ou se a lista de adjacência está vazia
    if(origem == NULL || origem->next == NULL) return false; //Falhou

    //Verificar se a adjacência é o primeiro da lista
    if(origem->next == adj) {
        Adjacente *aux = origem->next;

        //Verificar se adjacência é o único da lista
        if(origem->next->next == NULL) {
            origem->next = NULL;
        }
        else {
            origem->next = origem->next->next;
        }
        free(aux);
        return true;
    }

    Adjacente* atual = origem->next;
    Adjacente* anterior = atual;

    //Percorrer a lista de adjacências
    while(atual->destino != adj->destino) {

        if(atual->next != NULL) {
            anterior = atual;
            atual = atual->next;
        }
        else break;
    }

    //Verificar se encontrou a adjacência a ser removida
    if(atual->destino == adj->destino) {

        if(atual->next != NULL)
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
 * @brief Função para criar um vertice
 * 
 * @param id 
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
Vertice* ProcurarVertice(Vertice* inicio, int id) {

    Vertice* aux = inicio;

    //Percorrer a lista
    while(aux != NULL && aux->id != id)
    {
        if(aux->proximo != NULL) aux = aux->proximo;
        else break;
    }

    //Vertice encontrado
    if(aux != NULL && aux->id == id) return aux;

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
    if(ProcurarVertice(inicio,novo->id) != NULL) 
    {
        free(novo);
        return inicio;
    }

    Vertice* atual = inicio;
    Vertice* anterior = atual;

    //Percorrer a lista até encontrar a posição correspondente
    while(atual != NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c))) 
    {
        //Verificar se o próximo da lista é nulo
        if(atual->proximo != NULL) 
        {
            anterior = atual;
            atual = atual->proximo;
        }
        else break;//Parou o while
        
    }

    
    if(atual->proximo == NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c)))
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
    if(inicio == NULL || ProcurarVertice(inicio,v->id) == NULL) return inicio;


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
        while(atual != NULL && (atual->l != v->l || (atual->l == v->l && atual->c != v->c)))
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

/**
 * @brief Função para criar um grafo
 * 
 * @return GR* 
 */
GR* CriarGrafo(int numVertices) {
    
    GR* grafo;
    grafo = (GR*)malloc(sizeof(GR));

    if(grafo != NULL) {
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
bool GravarGrafo(char* nomeFicheiro, GR* grafo) {

    FILE* fp = fopen(nomeFicheiro, "wb");

    //Verificar se há erro ao abrir o ficheiro ou a lista está vazia
    if(fp == NULL || grafo->inicio == NULL) return false;

    //gravar o número de vertices
    fwrite(&grafo->numVertices, sizeof(int), 1, fp);

    //Gravar Vértices e adjacências
    Vertice* aux = grafo->inicio;

    Adjacente* Adj = NULL;
    int numAdj = 0;

    while (aux != NULL)
    {   
        fwrite(&aux->id, sizeof(int), 1, fp);
        fwrite(&aux->frequencia, sizeof(char), 1, fp);
        fwrite(&aux->l, sizeof(int), 1, fp);
        fwrite(&aux->c, sizeof(int), 1, fp);
        
        //gravar id do vertice destino
        Adj = aux->next;
        
        //número de adjacências
        numAdj = 0;

        while(Adj != NULL) {
            numAdj = numAdj + 1;
            Adj = Adj->next;
        }
        fwrite(&numAdj, sizeof(int), 1, fp);
        Adj = aux->next;

        while(Adj != NULL) {
            fwrite(&aux->next->destino, sizeof(int), 1, fp);
            Adj = Adj->next;
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
GR* LerGrafo(char* nomeFicheiro) {
    FILE* fp = fopen(nomeFicheiro, "rb");

    if(fp == NULL) return NULL;
    
    int numVertices;

    fread(&numVertices, sizeof(int), 1, fp);

    //Criar um grafo
    GR* grafo = CriarGrafo(numVertices);

    Vertice* aux;

    Adjacente* Adj = NULL;
    int numAdj = 0; 
    //Percorrer os vertices
    for(int i=0; i < grafo->numVertices; i=i+1) {
        
        int id, l, c;
        char f;

        //Ler Vertice
        fread(&id, sizeof(int), 1, fp);
        fread(&f, sizeof(char), 1, fp);
        fread(&l, sizeof(int), 1, fp);
        fread(&c, sizeof(int), 1, fp);

        //Criar Vertice
        aux = CriarVertice(id,f,l,c);
        
        //Inserir Vertice na lista
        grafo->inicio = InserirVertice(aux,grafo->inicio);

        //número de adjacências
        int numAdj = 0;
        Adj = aux->next;
        bool feedback = false;

        fread(&numAdj, sizeof(int), 1, fp);

        for(int j=0; j < numAdj; j=j+1) {
            int destino;
            fread(&destino, sizeof(int), 1, fp);
            Adj = CriarAdjacencia(destino);
            feedback = InserirAdjacencia(aux, Adj);
        }
        
    }

    fclose(fp);
    return grafo;
}

/**
 * @brief 
 * 
 * @param grafo 
 * @param id 
 * @return true 
 * @return false 
 */
bool ProcuraEmProfundidade(GR* grafo, int id) {

    if(grafo == NULL) return false;

    //Serve para marcar os vertices visitados na procura
    bool* visitado;
    visitado = (bool*)malloc(grafo->numVertices * sizeof(bool));

    if(visitado == NULL) return false;

    //Inicializar todos como false
    for(int i=0; i < grafo->numVertices; i=i+1) {
        visitado[i] = false;
    }

    Vertice* origem = ProcurarVertice(grafo->inicio, id);
    if(origem != NULL) {
        printf("Antenas alcançadas a partir da antena %d: \n", id);
        bool ok = dfs(grafo->inicio,origem,visitado);
        
        free(visitado);
        return true;
    }
    else {
        free(visitado);
        return false;
    }
}

/**
 * @brief 
 * 
 * @param inicio 
 * @param v 
 * @param visitado 
 * @return true 
 * @return false 
 */
bool dfs(Vertice* inicio, Vertice* v, bool* visitado) {
   
    if(v == NULL || visitado[v->id-1] == true) return false;
    

    visitado[v->id-1] = true;

    printf("Antena %d, (%d,%d)\n",v->id,v->l,v->c);

    Adjacente* Adj = v->next;
    

    while (Adj != NULL) {
        Vertice* proximo = ProcurarVertice(inicio, Adj->destino);
        dfs(inicio,proximo,visitado);
        Adj = Adj->next;
    }

    return true;
}

/**
 * @brief 
 * 
 * @param grafo 
 * @param v 
 * @return true 
 * @return false 
 */
bool ProcuraEmLargura(GR* grafo, Vertice* v) {

    //Verificar se o grafo e vertice são nulos
    if(grafo == NULL || v == NULL) return false;

    //Serve para marcar os vertices visitados na procura
    bool* visitado;
    visitado = (bool*)malloc(grafo->numVertices * sizeof(bool));

    if(visitado == NULL) return false;

    //Inicializar todos como false
    for(int i=0; i < grafo->numVertices; i=i+1) {
        visitado[i] = false;
    }

    Vertice* fila[grafo->numVertices];

    int frente=0, tras=0;

    visitado[v->id-1] = true;
    fila[tras++] = v;
    printf("Antenas alcançadas a partir da antena %d: \n", v->id);
    while(frente < tras) {
        Vertice* atual = fila[frente++];

        printf("Antena %d, (%d,%d)\n", atual->id, atual->l, atual->c);

        Adjacente* Adj = atual->next;
        while(Adj!=NULL) {

            //Procurar o vertice correspondente ao ID
            Vertice* vizinho = grafo->inicio;
            while(vizinho!=NULL && vizinho->id != Adj->destino) {
                vizinho=vizinho->proximo;
            }

            if(vizinho !=NULL && visitado[vizinho->id-1] == false) {
                visitado[vizinho->id-1] = true;
                fila[tras++] = vizinho;
            }

            Adj=Adj->next;
        }
    }

    free(visitado);
    return true;
}

bool ListarCaminhosRec(GR* grafo, Vertice* atual, Vertice* destino, bool* visitado, Vertice* caminho[], int nivel) {

    if(grafo == NULL || atual == NULL || destino == NULL) return false;

    visitado[atual->id-1] = true;
    caminho[nivel++] = atual;

    if(atual == destino) 
    {
        printf("Caminho:");
        for(int i=0; i<nivel; i=i+1) {
            Vertice* v = caminho[i]; 
            printf("(%d,%d)",v->l, v->c);
            if(i< nivel-1) printf("->");
        }
        printf("\n");
    }
    else 
    {
        //Percorrer a lista de adjacências
        Adjacente* a = atual->next;
        while(a!=NULL) {
            Vertice* v = ProcurarVertice(grafo->inicio,a->destino);
            if(v!=NULL && visitado[v->id-1] == false && v->frequencia == atual->frequencia) {
                ListarCaminhosRec(grafo,v,destino,visitado,caminho,nivel);
            }
            if(a->next!=NULL) a=a->next;
            else break;
        }
        /* 
        for(Adjacente* a = atual->next; a!= NULL; a=a->next) {
            Vertice* v = ProcurarVertice(grafo->inicio,a->destino);
            if(v!=NULL && visitado[v->id-1] == false && v->frequencia == atual->frequencia) {
                ListarCaminhosRec(grafo,v,destino,visitado,caminho,nivel);
            }

        }*/
    }

    visitado[atual->id-1] = false;
    return true;

}


bool ListarTodosCaminhos(GR* grafo, Vertice* origem, Vertice* destino) {
    
    
    if(grafo == NULL || origem == NULL || destino == NULL) return false;
    

    //Serve para marcar os vertices visitados na procura
    bool* visitado;
    visitado = (bool*)malloc(grafo->numVertices * sizeof(bool));

    if(visitado == NULL) return false;
    
    //Inicializar todos como false
    for(int i=0; i < grafo->numVertices; i=i+1) {
        visitado[i] = false;
    }

    Vertice* caminho[grafo->numVertices];
    bool ok = ListarCaminhosRec(grafo,origem,destino,visitado,caminho,0);

    free(visitado);
    return true;
}