#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int arvb_elemento;
typedef struct no_arvb{
    arvb_elemento info;
    struct no_arvb *le, *ld;
} no_arvb;

int menu(){
    cout<<"\n -------------------------------- ";
    cout<<"\n        ARVORE DE PESQUISA";
    cout<<"\n -------------------------------- ";
    cout<<"\n\n        <<<ESCOLHA >>>";
    cout<<"\n  [0] Sair";
    cout<<"\n  [1] Inserir";
    cout<<"\n  [2] Buscar";
    cout<<"\n  [3] Percorrer - pre-ordem";
    cout<<"\n  [4] Percorrer - in-ordem";
    cout<<"\n  [5] Percorrer - pos-ordem";
    cout<<"\n  [6] Eliminar";
    int esc;
    do{cout<<"\n    >>> __"; cin>>esc;}
    while(esc<0 || esc>9);
    return esc;
}

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

int buscar(no_arvb *raiz, arvb_elemento A){
    no_arvb *p; //cria uma variável que receba o endereço de um nó arvore
    p = raiz; // recebe o endereço da raiz

    while(p != NULL){ // enquanto o endereço contido em p não for nulo
        if(p->info == A) return 1; //se p->info for igual ao A, achamos na arvore e retorna 1
        if(A > p->info) p = p->ld; //se A for maior que o p->info, vamos caminhar para o lado direito
        else p = p->le; // se o A for menor que o p->info, vamos caminhar para esquerda
    }

    return 0; // caso o endereço de p for nulo, ele sai do looping e retorna zero, que significa que ele nao achou A na árvore
}

void inserir(no_arvb **raiz, arvb_elemento a){
    no_arvb *novo; //novo declarado para receber o endereço de um no_arvb
    novo = novo_no_arvb(); // alocação de memoria para esse novo no, info, ld, le null
    novo->info = a; // a informação do novo nó vale a

    if(*raiz == NULL){ // se a raiz for nula
        *raiz = novo; // a raiz recebe o endereço de novo e novo passa a ser a raiz da árvore
        return;
    }

    //se a raiz nao for nula
    no_arvb *p; //p declarado para receber o endereço de um no_arvb
    p = *raiz; //p recebe o endereço da raiz

    //enquando o p nao for nulo
    while(p != NULL){
        if( a < p->info) //se o a for menor que o p->info vamos trabalhar do lado esquerdo
            if(p->le != NULL) //se o link esquerdo nao for nulo, vamos andar com o p para esqueda
                p= p->le;
            else{ //se for nulo, o link esquedo recebe o endereço de novo
                p->le = novo; 
               return;
            }
        else //se o a for maior que o p->info vamos trabalhar do lado direito
            if(p->ld != NULL)  // se o link direito de p nao for nulo, vamos andar com p para a direita
                p= p->ld;
            else { // se for nulo, o link direito de p vai receber o endereço de novo
                p->ld = novo; 
                return;
            }
    }
}

void preordem (no_arvb * t){
    if(t != NULL)    {
        cout<<" "<<t->info;
        preordem (t->le);
        preordem (t->ld);
    }
}

void inordem (no_arvb * t){
    if(t != NULL)    {
        inordem (t->le);
        cout<<" "<<t->info;
        inordem (t->ld);
    }
}

void posordem (no_arvb * t){
    if(t != NULL)    {
        posordem (t->le);
        posordem (t->ld);
        cout<<" "<< t->info;
    }
}

int eliminar (no_arvb **t, arvb_elemento a){
    no_arvb *p, *pai, *desc, *aux;
    p=*t;
    pai = NULL;
    while(p!=NULL && p->info != a){
        pai = p;
        p = (a<p->info)? p->le: p->ld;
    }
    if(p == NULL)  return 0;
    if(p->le == NULL)
        desc = p->ld;
    else if(p->ld == NULL)
        desc = p->le;
    else 
    {
        aux = p;
        desc = p->ld;
        while (desc->le != NULL){
            aux = desc;
            desc = desc->le;
        }
        if(aux != p){
            aux->le = desc->ld;
            desc->ld = p->ld;
        }
        desc->le = p->le;
    }
    if (pai == NULL)
        *t = desc;
    else if (a < pai->info) 
        pai->le = desc;
    else
        pai->ld = desc;

    free(p);
    return 1; ///sucesso
}

int main(){
    no_arvb * raiz = NULL;
    arvb_elemento X;
    int esc;
    while((esc = menu()) != 0){
        switch(esc){
        case 0: cout<<"\n FIM DE PROGRAMA.... ";
            return 0;
        case 1: cout<<"\n <<< INSERIR >>>";
            cout<<"\n Info: "; cin>>X;
            inserir(&raiz, X);
            // cout<<"\n Numero nos: "<< conta_nos(raiz);
            // cout<<"\n Numero folhas: "<< conta_folha(raiz);
            break;
        case 2:cout<<"\n <<< BUSCAR >>>";
            cout<<"\n Info: ";cin>>X;
            cout<<"\n >>> "<< (buscar(raiz, X)? "Existe" : "Nao Existe") <<endl;
            break;
        case 3: cout<<"\n <<< PRE-ORDEM >>>";
            preordem(raiz);
            break;
        // case 4: cout<<"\n <<< IN-ORDEM >>>";
        //     inordem(raiz);
        //     break;
        // case 5: cout<<"\n <<< POS-ORDEM >>>";
        //     posordem(raiz);
        //     break;
        // case 6: cout<<"\n <<< ELIMINAR >>>";
        //     cout<<"\n Info: ";cin>>X;
        //     cout<<"\n >>> "<< (eliminar(&raiz, X)? "Eliminado com Sucesso" : "Nao Existe")<<endl;
        //     break;
        }///fim s/c
    }///fim while
    return 0;
}