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
Adjacente* CriarAdjacencia(int l, int c) {
    
    Adjacente* aux;
    aux = (Adjacente*)malloc(sizeof(Adjacente));

    if(aux!=NULL) {
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
bool InserirAdjacencia(Vertice* origem, Adjacente* novo) {

   
    //Verificar se o vertice pretence ao inicio da lista
    if(origem->next == NULL || novo->l < origem->next->l || (novo->l == origem->next->l && novo->c < origem->next->c))
    {
        novo->next = origem->next;
        origem->next = novo;
        return true;
    }
        
    Adjacente* atual = origem->next;
    Adjacente* anterior = atual;
    
    //Percorrer a lista até encontrar a posição correspondente
    while(atual != NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c))) 
    {
        //Verificar se o próximo da lista é nulo
        if(atual->next != NULL) {
            anterior = atual;
            atual = atual->next;
        }
        else break;//Parou o while
            
    }
    
    if(atual->next == NULL && (atual->l < novo->l || (atual->l == novo->l && atual->c < novo->c)))
    {
        //Insere no fim
        atual->next = novo;
    }
    else
    {
        //Insere o novo vertice entre dois vertices da lista
        anterior->next = novo;
        novo->next = atual;
        }

    return true; //Sucesso
}

/**
 * @brief Função para remover uma adjacência
 * 
 * @param origem vertice origem
 * @param adj adjacencia a ser removida
 * @return true 
 * @return false 
 */
bool RemoverAdjacencia(Vertice* origem, Adjacente* adj) {

    //Verificar se o Vertice origem é nulo ou se a lista de adjacência está vazia
    if(origem == NULL || origem->next == NULL) return false; //Falhou

    //Verificar se a adjacência é o primeiro da lista
    if(origem->next->l == adj->l || (origem->next->l == adj->l && origem->next->c == adj->c)) {
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
    while(atual->l != adj->l || (atual->l == adj->l && atual->c != adj->c)) {

        if(atual->next != NULL) {
            anterior = atual;
            atual = atual->next;
        }
        else break;
    }

    //Verificar se encontrou a adjacência a ser removida
    if(atual->l == adj->l && atual->c == adj->c) {

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
 * @brief Função para criar vertice
 * 
 * @param f frequência
 * @param l linha
 * @param c coluna
 * @return Vertice* 
 */
Vertice* CriarVertice(char f, int l, int c) {
    
    Vertice* aux;
    aux = (Vertice*)malloc(sizeof(Vertice));
    

    if(aux!=NULL) {
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
Vertice* ProcurarVertice(Vertice* inicio, int l, int c) {

    Vertice* aux = inicio;

    //Percorrer a lista
    while(aux != NULL && 
        (aux->l != l || (aux->l == l && aux->c != c)))
    {
        if(aux->proximo != NULL) aux = aux->proximo;
        else break;
    }

    //Vertice encontrado
    if(aux != NULL && aux->l == l && aux->c == c) return aux;

    //Vertice não encontrado
    return NULL;

}

/**
 * @brief Função para inserir um vertice na lista
 * 
 * @param novo novo vertice
 * @param inicio lista de vertices
 * @return Vertice* 
 */
Vertice* InserirVertice(Vertice* novo, Vertice* inicio, int* res) {

    *res = 0;

    //Verificar se já existe um Vertice com as mesmas coordenadas
    if(ProcurarVertice(inicio,novo->l,novo->c) != NULL) 
    {
        free(novo);
        return inicio;
    }

    //Verificar se o vertice pretence ao inicio da lista
    if(inicio == NULL || novo->l < inicio->l || (novo->l == inicio->l && novo->c < inicio->c))
    {
        novo->proximo = inicio;
        inicio = novo;
        *res = 1;
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

    *res = 1;
    return inicio;
}

/**
 * @brief Função para remover o vertice da lista
 * 
 * @param v vertice a ser removido
 * @param inicio lista de vertices
 * @return Vertice* 
 */
Vertice* RemoverVertice(Vertice* v, Vertice* inicio, int* res) {
    
    *res = 0;
    //Verificar se a lista está vaiza ou se o vertice a ser removido não existe na lista
    if(inicio == NULL || ProcurarVertice(inicio,v->l,v->c) == NULL) return inicio;

    //Verificar se o vértice a ser removido é o primeiro da lista
    if(v->l == inicio->l && v->c == inicio->c) 
    {
        Vertice* aux = inicio;
        Adjacente* auxAdj = aux->next;
        Adjacente* remover = CriarAdjacencia(v->l,v->c);

        //Procurar outros vertices para remover adjacência do vertice a ser removido
        while(auxAdj!=NULL) {

            if(ProcurarVertice(inicio,auxAdj->l,auxAdj->c) != NULL) {
                Vertice* verticeAdjacente = ProcurarVertice(inicio,auxAdj->l,auxAdj->c);
                bool ok = RemoverAdjacencia(verticeAdjacente,remover);
            }

            if(auxAdj->next != NULL) auxAdj = auxAdj->next;
            else break;
        }



        inicio = inicio->proximo;
        free(aux);
        *res = 1;
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

            Adjacente* auxAdj = atual->next;
            Adjacente* remover = CriarAdjacencia(v->l,v->c);

            //Procurar outros vertices para remover adjacência do vertice a ser removido
            while(auxAdj!=NULL) {
                if(ProcurarVertice(inicio,auxAdj->l,auxAdj->c) != NULL) {
                    Vertice* verticeAdjacente = ProcurarVertice(inicio,auxAdj->l,auxAdj->c);
                    bool ok = RemoverAdjacencia(verticeAdjacente,remover);
            }

                if(auxAdj->next != NULL) auxAdj = auxAdj->next;
                else break;
            }

            anterior->proximo = atual->proximo;
            free(atual);
        }
        *res = 1;
        return inicio;
    }
    
}

/**
 * @brief Função para criar um grafo
 * 
 * @param numVertices 
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
        fwrite(&aux->f, sizeof(char), 1, fp);
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
            fwrite(&Adj->l, sizeof(int), 1, fp);
            fwrite(&Adj->c, sizeof(int), 1, fp);
            
            if(Adj->next != NULL) Adj = Adj->next;
            else break;
            
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
    bool ok = false;
    //Percorrer os vertices
    for(int i=0; i < grafo->numVertices; i=i+1) {
        
        int l, c;
        char f;

        //Ler Vertice
        fread(&f, sizeof(char), 1, fp);
        fread(&l, sizeof(int), 1, fp);
        fread(&c, sizeof(int), 1, fp);

        //Criar Vertice
        aux = CriarVertice(f,l,c);
        
        int *res;
        //Inserir Vertice na lista
        grafo->inicio = InserirVertice(aux,grafo->inicio,res);

        //número de adjacências
        int numAdj = 0;
        Adj = aux->next;
        bool feedback = false;

        fread(&numAdj, sizeof(int), 1, fp);

        for(int j=0; j < numAdj; j=j+1) {
            int linha, coluna;
            fread(&linha, sizeof(int), 1, fp);
            fread(&coluna, sizeof(int), 1, fp);
            Adj = CriarAdjacencia(linha,coluna);
            feedback = InserirAdjacencia(aux, Adj);
        }
        
    }

    fclose(fp);
    return grafo;
}

 bool GravarGrafoFileTexto(char* nomeFicheiro, GR* grafo, Tamanho* matriz) {

        FILE *fp;//file point

    //Verificar se a lista está vazia
    if(grafo->inicio == NULL) return false;

    fp = fopen(nomeFicheiro, "wt");

    if(fp !=NULL) 
    {
        Vertice *aux = grafo->inicio;

        for(int l=0; l < matriz->nLinhas; l=l+1) {

            for(int c=0; c < matriz->nColunas; c=c+1) {
                if(aux->l == l && aux->c == c) 
                {
                    fprintf(fp,"%c", aux->f);
                    
                    //Passa para o próximo elemento
                    if(aux->proximo != NULL)  aux = aux->proximo;

                }
                else fprintf(fp,".");
                
            }

            fprintf(fp,"\n");
        }

        fclose(fp);
        return true;
    }

    else return false;
}


GR* LerGrafosFileTexto(char* nomeFicheiro, Tamanho* matriz) {
    FILE *fp;//file point

    fp = fopen(nomeFicheiro, "rt");

    int nVertice=0;

    if(fp != NULL) 
    {
        Vertice *inicio = NULL;
        Vertice *aux;
        
        char c;
        bool contadorColuna=false;

        int auxColunas = 0;//indica a coluna da matriz que está atualmente

        int* res;
        //equanto não chegar ao final do ficheiro
        while(!feof(fp)) {

            c = fgetc(fp);
            if(c != '.' && c != '\n' && c != -1) {
                aux = CriarVertice(c,matriz->nLinhas,auxColunas);
                inicio = InserirVertice(aux,inicio,res);
                if(*res==1)nVertice++;
            }
            if (c == '\n') {
                matriz->nLinhas++;
                auxColunas = -1;
                if(contadorColuna == false) contadorColuna = true; 
            }

            if(contadorColuna == false) matriz->nColunas++;
            auxColunas++;
            
        }

        GR* grafo = CriarGrafo(nVertice);
        grafo->inicio = inicio;



        //Inserir as adjacencias de cada vertice
        
        inicio = grafo->inicio;
        aux = grafo->inicio;

        while (inicio != NULL) {
            Vertice* v = inicio;
            while(aux != NULL) {

                if(v->f == aux->f && (v->l != aux->l || (v->l == aux->l && v->c != aux->c))) {
                    Adjacente* novo = CriarAdjacencia(aux->l,aux->c);
                    InserirAdjacencia(v,novo);
                }

                aux = aux->proximo;
            }

            inicio = inicio->proximo;
            aux = grafo->inicio;
        }
        


        fclose(fp);
        return grafo;

    }
    else return NULL;
}

/**
 * @brief 
 * 
 * @param lista 
 * @return true 
 * @return false 
 */
bool MostrarLista(Adjacente* lista) {
    
    if(lista == NULL) return false;

    Adjacente* aux = lista;

    while(aux != NULL) {
        printf("(%d,%d)\n",aux->l,aux->c);
        aux = aux->next;
    }
    return true;
}

/**
 * @brief Função para inicializar o campo visitado como false dos vertices
 * 
 * @param grafo 
 * @return true 
 * @return false 
 */
GR* InicializarVisitados(GR* grafo) {

    if(grafo == NULL || grafo->inicio == NULL) return false;

    //Inicializar os visitados
    Vertice* aux = grafo->inicio;
    while(aux != NULL) {
        aux->visitado = false;
        aux = aux->proximo;
    }

    return grafo;
}

/**
 * @brief Função para inserir o caminho em uma lista
 * 
 * @param lista 
 * @param l linha
 * @param c coluna
 * @return true 
 * @return false 
 */
Adjacente* InserirCaminho(Adjacente* lista, int l, int c) {

    Adjacente* novo = CriarAdjacencia(l,c);

    //Insere no inicio da lista
    if(lista == NULL) {
        lista = novo;
    } 
    
    //Inserir no fim da lista
    else {
        Adjacente* aux = lista;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
    }
    
    return lista;
}

/**
 * @brief Função que procura em profundidade a partir de uma determinada antena
 * 
 * @param grafo 
 * @param origem vertice de origem
 * @return Adjacente* 
 */
Adjacente* ProcuraEmProfundidade(GR* grafo, Vertice* origem) {

    if(grafo == NULL || origem == NULL) return NULL;

    //Inicializar todos como false
    grafo = InicializarVisitados(grafo);

    Adjacente* lista = NULL;
    dfs(grafo->inicio,origem,&lista);
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
bool dfs(Vertice* inicio, Vertice* origem, Adjacente** lista) {
   
    if(origem == NULL || origem->visitado == true) return false;
    
    origem->visitado = true;

    *lista = InserirCaminho(*lista, origem->l,origem->c);

    Adjacente* adj = origem->next;
    while (adj != NULL) {
        Vertice* proximo = ProcurarVertice(inicio, adj->l, adj->c);
        dfs(inicio,proximo,lista);
        adj = adj->next;
    }

    return true;
}

/**
 * @brief Procura em largura a partir de uma determinada antena (BFS)
 * 
 * @param grafo 
 * @param origem vertice de origem
 * @return Adjacente* 
 */
Adjacente* ProcuraEmLargura(GR* grafo, Vertice* origem) {

    //Verificar se o grafo e vertice são nulos
    if(grafo == NULL || origem == NULL) return NULL;

    //Inicializar todos como false
    grafo = InicializarVisitados(grafo);

    //lista para guardar as coordenadas dos caminhos percorridos
    Adjacente* lista = NULL;

    //Vertice* fila[grafo->numVertices];
    Vertice** fila = (Vertice**)malloc(grafo->numVertices * sizeof(Vertice*));
    if (fila == NULL) return NULL; // Handle allocation failure
    int frente=0, tras=0;

    //Marcar como visitado e inserir na fila
    origem->visitado = true;
    fila[tras++] = origem;

    //Enquanto houver elementos na fila
    while(frente < tras) {
        //Retirar o próximo vértice da fila
        Vertice* atual = fila[frente++];

        //Inserir um caminho para a lista
        lista = InserirCaminho(lista,atual->l,atual->c);

        //Percorrer todos os visinhos do vértice atual
        Adjacente* adj = atual->next;
        while(adj!=NULL) {
           //Procurar o vertice correspondente às coordenadas
           Vertice* vizinho = ProcurarVertice(grafo->inicio,adj->l,adj->c);
            if(vizinho !=NULL && vizinho->visitado == false) {
                vizinho->visitado = true;
                fila[tras++] = vizinho;
            }

            adj=adj->next;
        }
    }

    free(fila);
    return lista;
}

/**
 * @brief Função para procurar todos os caminhos possíveis
 * 
 * @param grafo 
 * @param atual vertice atual
 * @param destino vertice destino
 * @param caminhoAtual 
 * @param listaCaminhos Lista de caminhos possíveis 
 * @return true 
 * @return false 
 */
Caminho* ProcurarTodosCaminhos(GR* grafo, Vertice* atual, Vertice* destino, Adjacente* caminhoAtual, Caminho* listaCaminhos) {

    if(grafo == NULL || atual == NULL || destino == NULL) return false;

    atual->visitado = true;

    //Criar novo nó com a posição atual
    Adjacente* novoNo = CriarAdjacencia(atual->l, atual->c);
    novoNo->next = caminhoAtual;
    caminhoAtual = novoNo;

    if (atual == destino) {
        // Copiar o caminho atual
        Adjacente* copia = NULL;
        Adjacente* aux = caminhoAtual;

        // Copiar em ordem inversa (porque estamos a inserir no início)
        while (aux != NULL) {
            Adjacente* novo = CriarAdjacencia(aux->l, aux->c);
            if (copia == NULL) copia = novo;
            else {
                novo->next = copia;
                copia = novo;
            }
            aux = aux->next;
        }

        // Adicionar à lista de caminhos
        Caminho* novoCaminho = (Caminho*)malloc(sizeof(Caminho));

        //Guarda na lista de adjacencias
        novoCaminho->inicio = copia;

        //Guarda na lista de caminhos
        novoCaminho->proximo = listaCaminhos;
        listaCaminhos = novoCaminho;
    } else {
        //Percorrer as adjacências
        Adjacente* a = atual->next;
        while(a != NULL) {
            Vertice* v = ProcurarVertice(grafo->inicio, a->l, a->c);
            if (v && !v->visitado && v->f == atual->f) {
                listaCaminhos = ProcurarTodosCaminhos(grafo, v, destino, caminhoAtual, listaCaminhos);
            }
            a = a->next;
        }

    }

    atual->visitado = false;
    return listaCaminhos;
}

/**
 * @brief Função para procurar todas as intersecções de pares de antenas com ressonância distintas
 * 
 * @param grafo 
 * @param f1 frequência de uma antena
 * @param f2 frequência de outra antena
 * @return Adjacente* 
 */
Adjacente* Intersecoes(GR* grafo, char f1, char f2) {
    
    if(grafo == NULL) return NULL;

    Adjacente* ListaInterseta = NULL;

    Vertice* v1 = grafo->inicio;

    while(v1 != NULL) {
        if(v1->f == f1) {
            Vertice* v2 = grafo->inicio;
            while(v2 != NULL) {
                if(v2->f == f2 &&
                   v2->l == v1->l &&
                   v2->c == v1->c) {

                    Adjacente* novo = CriarAdjacencia(v1->l,v1->c);
                    novo->next = ListaInterseta;
                    ListaInterseta = novo;
                   }
                   v2 = v2->proximo;
            }
        }
        v1 = v1->proximo;
    }

    return ListaInterseta;
}