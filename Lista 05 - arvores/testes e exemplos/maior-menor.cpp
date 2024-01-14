/*Construir uma função que verifica quantos nos da arvore possuem apenas um descendente*/

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

// maior elemento com recursiva
arvb_elemento maior_elemento(no_arvb *p){
    if(p->ld != NULL) 
        return maior_elemento(p->ld);
    return p->info;
}

// // maior elemento sem recursiva
// int maior_elemento(no_arvb *raiz) {
//     no_arvb *p;
//     p = raiz;
//     int maior = p->info; 

//     while (p != NULL) {
//         if (p->info > maior) {
//             maior = p->info;
//         }
//         p = p->ld;
//     }

//     return maior;
// }

arvb_elemento menor_elemento(no_arvb *p){
    if(p->le != NULL) 
        return menor_elemento(p->le);
    return p->info;
}

int main(){
    no_arvb *raiz = NULL;
    arvb_elemento V;

    //popular arvore
    srand(time(0));
    int num = 12;
    int v[] = {61,43,16,51,55,11,32,66,79,82,77,89};
    for(int i=0; i<num; i++){
        arvb_elemento a =v[i];
        inserir(&raiz,a);
    }

    cout << "\nIn-ordem: ";
    inordem(raiz);

    int maior = maior_elemento(raiz);
    cout << "\nMaior elemento: " << maior;

    int menor = menor_elemento(raiz);
    cout << "\nMenor elemento: " << menor;

    return 0;
}