/*Considere uma árvore qualquer, cujo nó raiz está armazenado na variável raiz. Construir uma função que recebe o endereço do nó raiz e conta quantos nós a árvore possui. Retorna pelo return o numero de nós.*/

#include <iostream>
#include <time.h>
#define GR_MAX 6

using namespace std;

typedef int arv_elemento;

typedef struct no_arv{
    arv_elemento info;
    no_arv* link[GR_MAX];
} no_arv;

typedef no_arv *queue_element;
#include "queue_lg.h"

typedef no_arv *stack_element;
#include "stack.h"

// Funções para testar o exercício -----------------------------------
no_arv *novo_no_arv(){
    no_arv *nv;
    nv = (no_arv *)malloc(sizeof(no_arv));
    if (nv == NULL){
        cout << "\n Erro de alocacao!";
        exit(1);
    }
    for (int i = 0; i < GR_MAX; i++)
        nv->link[i] = NULL;
    return nv;
}

void inserir_por_nivel(no_arv**raiz, int grau, arv_elemento x){

    queue_element v;
    no_arv* novo;
    Queue F; initQueue(F);

    novo = novo_no_arv();

    novo->info = x;

    if(*raiz == NULL){
           *raiz=novo;
           return;
    }

    insert(F,*raiz);

    while(!isEmptyQ(F)){
        v = eliminate(F);
        for(int j=0;j<grau;j++){
            if(v->link[j]== NULL){
                v->link[j] = novo;
                return;
            }
            else
                insert(F,v->link[j]);
        }
   }
}

void percorrer_largura(no_arv *raiz, int grau){
    queue_element v;
    Queue Q;
    initQueue(Q);

    if(raiz == NULL) return;

    insert(Q,raiz);

    while(!isEmptyQ(Q)){
        v = eliminate(Q);
        cout << " " << v->info;
        for(int i=0; i<grau; i++){
            if(v->link[i] != NULL){
                insert(Q,v->link[i]);
            }
            else break;
        }
    }

}



// Resolução do problema ---------------------------------------------
int contar_nos(no_arv *r, int grau){
    Queue Q;
    initQueue(Q);
    queue_element v;

    int cont = 0;

    if(r == NULL) return 0;

    insert(Q,r);

    while(!isEmptyQ(Q)){
        v = eliminate(Q);
        cont ++;
        for(int i=0; i< grau; i++){
            if(v->link[i] != NULL){
                insert(Q,v->link[i]);
            }
            else break;
        }
    }
    return cont;
}

int main(){
    no_arv *raiz;
    raiz = NULL;

    //para popular a lista automaticamente
    srand(time(0));
    int grau = rand() % GR_MAX + 1;
    int num_nos = rand() % 16 + 5;
    for(int i = 0; i < num_nos; i++){
        arv_elemento a = rand() % 50;
        inserir_por_nivel(&raiz,grau,a);
    }

    //para conferir as variáveis sorteadas
    cout << "\nGrau: " << grau << endl;
    cout << "Num_nos: " << num_nos;

    cout << "\n\nArvore (percorrer por largura): ";
    percorrer_largura(raiz,grau);

    int cont = contar_nos(raiz,grau);

    cout << "\nExistem " << cont << " nos na arvore.";

    return 0;
}