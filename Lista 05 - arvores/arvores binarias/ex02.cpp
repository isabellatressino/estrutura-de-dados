/*Dada duas árvores binárias A e B. Construir uma função que verifica se a árvore B está contida na A. A árvore B é uma árvore com apenas dois níveis compondo uma família nodal completa. Isto é, B é uma árvore composta pelo nó raiz, descendente esquedo e descendente direito. Retornar 1 se sim e 0 se não.*/

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

int verificar(no_arvb *rA, no_arvb *rB){
    no_arvb *p;
    p = rA;
    while(p != NULL && p->info != rB->info){
        if(rB->info < p->info)
            p = p->le;
        else
            p = p->ld;
    }

    if(p == NULL) return 0;
    if(p->le == NULL || p->ld == NULL) return 0;
    if(p->le->info == rB->le->info && p->ld->info == rB->ld->info) return 1;

}

int main(){
    no_arvb *raizA = NULL;
    no_arvb *raizB = NULL;

    //popular arvore A
    int v[] = {50,20,10,40,30,45,80,60,70,75,90};
    for(int i=0; i<11; i++){
        arvb_elemento a = v[i];
        inserir(&raizA,a);
    }

    //popular arvore B
    int w[] = {60,12,11};
    for(int i=0; i<3; i++){
        arvb_elemento b = w[i];
        inserir(&raizB,b);
    }

    cout << "\nIn-ordem A: ";
    inordem(raizA);

    cout << "\nIn-ordem B: ";
    inordem(raizB);

    int ret = verificar(raizA,raizB);
    if(ret == 0)
        cout << "\nB nao esta contido em A";
    else
        cout << "\nB esta contido em A";

    return 0;
}