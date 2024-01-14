/*exercicio 5*/

#include <iostream>
using namespace std;

typedef int elemento;

typedef struct no{
    elemento info;
    no* link;
}no;

no* init(){
    return NULL;
}

no* novo_no(){
    no* novo;
    novo = (no*) malloc(sizeof(no));
    if(novo == NULL) exit(1);
    return novo;
}

void imprime(no* pri){
  no* p;
  p = pri;
  while(p != NULL){
    cout << p->info << " ";
    p = p->link;
  }
}

void inserir_final(no**pri, elemento a){
    no *novo, *p;
    novo = novo_no();
    novo->info = a;
    novo->link = NULL;
    p = *pri;
    while(p!=NULL && p->link!=NULL){
        p = p->link;
    }
    if(p==NULL) *pri = novo;
    else p->link = novo;
}

float contar_rep(no*pri){
    int rep, contar;
    elemento maior;
    no *p,*q;
    rep = 0;
    p = pri;
    if(pri == NULL) return -1,0;
    while(p->link != NULL){
        contar = 1;
        q = p->link;
        while(q != NULL){
            if(p->info == q->info){
                contar++;
                q=q->link;
            }
        }
        if(contar > rep){
            rep = contar;
            maior = p->info;
        }
        p = p->link;
    }
    return contar,rep;
}

//pri é uma variavel ponteiro que guarda o endereço do primeiro nó

int main(){

    no *pri;
    elemento valor;
    float ret1, ret2;

    pri = init();

    cout << "Insira 10 valores na lista." << endl;
    for(int i=0;i<10;i++){
        cout << i+1 << "o. Valor: ";
        cin >> valor;
        inserir_final(&pri,valor);
    }

    imprime(pri);

    ret1, ret2= contar_rep(pri);
    if(ret1 == -1){
        cout << "Lista vazia." << endl;
    }
    else{
        cout << "" << ret1 << " " << ret2 << endl;
    }

    return 0;
}