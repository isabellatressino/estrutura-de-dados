/*Construir uma função recursiva que recebe o endereço da raiz e localiza um elemento V lido na main e passado pela lista de parametros. Se existir retorne pelo return o endereço, caso nao existir retornar NULL*/

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

no_arvb* localizar(no_arvb *t, arvb_elemento v){
    if(t == NULL || t->info == v) return t;
    if(v < t->info)
        return localizar(t->le,v);
    else
        return localizar(t->ld,v);
}

int main(){
    no_arvb *raiz = NULL;
    arvb_elemento V;

    //popular arvore
    srand(time(0));
    int num = rand() % 16 + 5;
    for(int i=0; i<num; i++){
        arvb_elemento a = rand() % 50;
        inserir(&raiz,a);
    }

    cout << "\nIn-ordem: ";
    inordem(raiz);

    cout << "\nLocalizar valor: ";
    cin >> V;

    no_arvb *endereco = localizar(raiz,V);

    cout << "\nEndereco = " << endereco;

    return 0;
}