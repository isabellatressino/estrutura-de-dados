/*Construir uma função que conta quantos nós tem a árvore binária*/

#include <iostream>
#include <time.h>

using namespace std;

typedef int arvb_elemento;

typedef struct no_arvb{
    arvb_elemento info;
    struct no_arvb *le, *ld;
}no_arvb;

no_arvb* novo_no_arvb(){
    no_arvb* nv;
    nv = (no_arvb*) malloc (sizeof(no_arvb));
    if(nv == NULL){
        cout<<"\n Erro de alocacao!";
        exit(1);
    }
    nv->le = nv->ld = NULL;
    return nv;
}

void inserir(no_arvb ** raiz, arvb_elemento a){

    no_arvb * novo;
    novo = novo_no_arvb();
    novo->info=a;

    if(*raiz == NULL){
        *raiz = novo;
        return;
    }

    no_arvb *p;
    p=*raiz;

    while(p != NULL){
        if( a < p->info)
            if(p->le != NULL)
                p = p->le;
            else{
                p->le = novo;
               return;
            }
        else
            if(p->ld != NULL) 
                p = p->ld;
            else {
                p->ld = novo;
                return;
            }
    }
}

void inordem (no_arvb *t){
    if(t != NULL)    {
        inordem(t->le);
        cout << " " << t->info;
        inordem(t->ld);
    }
}

int contar_nos(no_arvb *t){
    if(t == NULL) return 0;
    return 1 + contar_nos(t->le) + contar_nos(t->ld);
}

int main(){
    no_arvb *raiz = NULL;

    //popular arvore
    srand(time(0));
    int num = rand() % 16 + 5;
    for(int i=0; i<num; i++){
        arvb_elemento a = rand() % 50;
        inserir(&raiz,a);
    }

    cout << "\nIn-ordem: ";
    inordem(raiz);

    int cont = contar_nos(raiz);
    cout << "\nNumero de nos = " << cont;

    return 0;
}