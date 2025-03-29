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
 * @brief Função que cria um elemento
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
 * @brief Função que adiciona um elemento no início da lista
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
 * @brief Função que adiciona um elemento no fim da lista
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
 * @brief Função que insere um elemento na lista de forma ordenada através das coordenadas
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
 * @brief Função que procura um elemento em específico na lista
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
 * @brief Função que remove um elemento em específico da lista
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

/**
 * @brief Função para mostrar a lista na consola em forma de matriz
 * 
 * @param inicio 
 * @return true 
 * @return false 
 */
bool ListarMatriz(Elemento *inicio, Tamanho* matriz) {

    //Se a lista estiver vazia não mostra nada na consola
    if(inicio == NULL) return false;
    
    Elemento *aux = inicio;

    //Percorrer a "matriz"
    for(int l=0; l < matriz->nLinhas; l=l+1) {

        for(int c=0; c < matriz->nColunas; c=c+1) {

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

/**
 * @brief Função para gravar a lista num ficheiro txt em forma de matriz
 * 
 * @param nomeFicheiro 
 * @param inicio 
 * @return true 
 * @return false 
 */
bool GravarElementoFicheiro(char* nomeFicheiro, Elemento* inicio, Tamanho* matriz) {

    FILE *fp;//file point

    //Verificar se a lista está vazia
    if(inicio == NULL) return false;

    fp = fopen(nomeFicheiro, "wt");

    bool acabou = false;

    if(fp !=NULL) 
    {
        Elemento *aux = inicio;

        while(acabou!=true) 
        {
        for(int l=0; l < matriz->nLinhas; l=l+1) {

            for(int c=0; c < matriz->nColunas; c=c+1) {
                if(aux->l == l && aux->c == c) 
                {
                    fprintf(fp,"%c", aux->tipo);

                    //Passa para o próximo elemento
                    if(aux->p !=NULL) aux = aux->p;
                    else acabou=true;

                }
                else 
                {
                    fprintf(fp,".");
                }

            }
            fprintf(fp,"\n");
        }
        
        }

        fclose(fp);
        return true;

    }
    else {
        return false;
    }

}

/**
 * @brief Função para ler um ficheiro txt, calcular a dimensão da matriz e guardar os elementos numa lista 
 * 
 * @param nomeFicheiro 
 * @return Elemento* 
 */
Elemento *LerElementosFicheiro(char* nomeFicheiro, Tamanho* matriz) {

    FILE *fp;//file point

    fp = fopen(nomeFicheiro, "rt");

    if(fp != NULL) 
    {
        Elemento *inicio = NULL;
        Elemento *aux;
        
        char c;
        bool PararContarColuna=false;

        int auxColunas = 0;//indica a coluna da matriz que está atualmente

        //equanto não chegar ao final do ficheiro
        while(!feof(fp)) {

            c = fgetc(fp);
            if(c != '.' && c !='#' && c != '\n' && c == 'A') {
                aux = CriaElemento(c,matriz->nLinhas,auxColunas);
                inicio = InsereOrdenado(inicio,aux);
            }
            if (c == '\n') {
                matriz->nLinhas++;
                auxColunas = -1;
                if(PararContarColuna == false) PararContarColuna = true; 
            }

            if(PararContarColuna == false) matriz->nColunas++;
            auxColunas++;
            
        }
        fclose(fp);
        return inicio;

    }
    else {
        return NULL;
    }

}


Elemento *CalcularEfeitoNefasto(Elemento *inicio, Tamanho* matriz) {

    //Verificar se a lista está vazia
    if(inicio == NULL) return inicio;
    
    Elemento *aux = inicio;
    Elemento *aux2 = aux;
    bool acabou = false;

    while(acabou == false) {

        //Passar para a próxima posição
        if(aux->p != NULL) 
        {
            aux = aux->p;
        }
        else 
        {
            acabou = true;
        }

        //Verificar se estão na mesma linha. Se é da mesma frequênica e se não é um efeito nefasto
        if(aux2->l == aux->l && aux2 != aux && 
        aux2->tipo != '#' && aux->tipo != '#') {

            //Calcular a distancia entre as antenas
            int distancia = aux->c - aux2->c;
            Elemento *nefasto;

            //Verificar se as coordenadas do efeito nefasto estão dentro dos limites da dimensão da matriz
            if((aux2->l < matriz->nLinhas && aux2->l >= 0) && ((aux2->c-distancia) < matriz->nColunas && (aux2->c-distancia) >= 0)) 
            {
                nefasto = CriaElemento('#',aux2->l,aux2->c-distancia);
                inicio = InsereOrdenado(inicio,nefasto);
                printf("Nefasto 1 = (%d,%d)\n",aux2->l,aux2->c-distancia);
            }

            if((aux->l < matriz->nLinhas && aux->l >= 0) && ((aux->c+distancia) < matriz->nColunas && (aux->c+distancia) >= 0)) 
            {
                nefasto = CriaElemento('#',aux->l,aux->c+distancia);
                inicio = InsereOrdenado(inicio,nefasto);
                printf("Nefasto 2 = (%d,%d)\n",aux->l,aux->c+distancia);
            }
            

        }
    }
    return inicio;
}