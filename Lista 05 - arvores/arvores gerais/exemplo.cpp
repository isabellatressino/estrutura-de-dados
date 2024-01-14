#include <iostream>
#define GR_MAX 6

using namespace std;

typedef char arv_elemento;

typedef struct no_arv{
    arv_elemento info;
    no_arv* link[GR_MAX];
} no_arv;

typedef no_arv* queue_element;
#include "queue_lg.h"

typedef no_arv* stack_element;
#include "stack.h"

// protótipos
no_arv* novo_no_arv();
void inserir_por_nivel(no_arv**raiz, int grau, arv_elemento a);
void percorrer_largura (no_arv * raiz, int grau);
void percorrer_profundidade(no_arv * raiz, int grau);

int main(){

    no_arv* raiz;
    raiz = NULL;
    arv_elemento x;
    int grau;
    ///popular a árvore de GRAU (lido) por nivel - largura
    int N;
    cout<<"\n Grau da arvore:(max "<<GR_MAX<<"): ";
    do{cin>> grau;}while(grau<1||grau>GR_MAX);//validar GR_MAX
    cout<<"\n Numero de nos: ";cin >>N;

    for(int i=1;i<=N;i++){
        cout<< i <<"o. :"; cin>>x;
        inserir_por_nivel(&raiz,grau,x);
    }
    ///IMPRIMIR os valores da árvore - largura e profundidade

    cout<<"\n Valores da Arvore Busca em Largura \n";
    percorrer_largura (raiz,grau);
    cout<<"\n Valores da Arvore Busca em Profundidade \n";
    percorrer_profundidade(raiz,grau);
   return 0;
}
no_arv* novo_no_arv(){
    no_arv* nv;
    nv = (no_arv*) malloc (sizeof(no_arv));
    if(nv == NULL){
        cout<<"\n Erro de alocacao!";
        exit(1);
    }
    for(int i=0;i<GR_MAX;i++)nv->link[i]=NULL;
    return nv;
}

void inserir_por_nivel(no_arv**raiz, int grau, arv_elemento x){

    queue_element v;
    no_arv* novo;
    Queue F; initQueue(F);

    novo=novo_no_arv(); // alocação de memória para um novo nó

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

void percorrer_largura (no_arv * raiz, int grau){

    queue_element v;

    Queue F; initQueue(F);

    if(raiz==NULL)return;
    insert(F, raiz);
    while(!isEmptyQ(F)){
        v = eliminate(F);
        cout<<"   "<<v->info;
        for(int j=0;j<grau;j++)
            if(v->link[j]!=NULL)
               insert(F,v->link[j]);
            else break;
    }
}



void percorrer_profundidade (no_arv * raiz, int grau){

    stack_element v;

    Stack P; initStack(P);

    if(raiz==NULL)return;
    push(P, raiz);
    while(!isEmpty(P)){
        v = pop(P);
        cout<<"   "<<v->info;
        for(int j= grau-1;j>=0;j--)
            if(v->link[j]!=NULL)
               push(P,v->link[j]);
    }
}