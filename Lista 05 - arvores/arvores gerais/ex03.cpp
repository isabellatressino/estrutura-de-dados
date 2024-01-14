/*Considere uma ravore qualquer. Construir uma função que recebe o endereço do no raiz e conta quantos nos dessa arvore possuem apenas um descendente.*/

#include <iostream>
#include <time.h>
#define GR_MAX 6
using namespace std;

typedef int arv_elemento;

typedef struct no_arv{
    arv_elemento info;
    no_arv *link[GR_MAX];
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

void inserir_por_nivel(no_arv **raiz, int grau, arv_elemento a){
    queue_element v;
    Queue Q;
    initQueue(Q);

    no_arv *novo = novo_no_arv();
    novo->info = a;

    if(*raiz == NULL){
        *raiz = novo;
        return;
    }

    insert(Q,*raiz);

    while(!isEmptyQ(Q)){
        v = eliminate(Q);
        for(int i=0; i < grau; i++){
            if(v->link[i] == NULL){
                v->link[i] = novo;
                return;
            }
            else insert(Q,v->link[i]);
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
        cout << "  " << v->info;
        for(int i=0; i < grau; i++){
            if(v->link[i] != NULL){
                insert(Q,v->link[i]);
            }
            else break;
        }
    }
}


// Resolução do problema ---------------------------------------------

int contar_um_descendente(no_arv *raiz, int grau){
    queue_element v;
    Queue Q;
    initQueue(Q);
    int cont = 0;

    if(raiz == NULL) return 0;

    insert(Q,raiz);

    while(!isEmptyQ(Q)){
        int contLinks = 0;
        v = eliminate(Q);
        for(int i = 0; i < grau; i++){
            if(v->link[i] != NULL){
                contLinks ++;
                insert(Q,v->link[i]);
            }
            else break;
        }
        if(contLinks == 1){
            cont ++;
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

    cout << "\nArvore (largura): ";
    percorrer_largura(raiz,grau);

    int cont = contar_um_descendente(raiz,grau);
    cout << "\nNumero de nos com apenas um descendente " << cont;

}