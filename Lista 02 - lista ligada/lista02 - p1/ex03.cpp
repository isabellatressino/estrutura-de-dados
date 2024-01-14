/*Dada uma lista ligada contendo numeros inteiros desordenados. Construir uma função que verifica se há algum numero repetido na lista ou nao. Caso exista alguma repetiçao retornar 1, senao retornar 0. (ND 2)*/

#include <iostream>
using namespace std;

typedef int elemento;
typedef struct no{
    elemento info;
    no *link;
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

void imprime(no* pri){
  no* p;
  p = pri;
  while(p != NULL){
    cout << p->info << " ";
    p = p->link;
  }
}

int repeticao(no* pri){
    no *p, *c;
    p = pri;
    while(p != NULL){
        c = p->link; // inicializa c com o nó após p
        while(c != NULL){
            if(c->info == p->info)
                return 1;
            c = c->link; 
        }
        p = p->link; 
    }
    return 0;
}

int main(){

    no *pri;
    elemento valor;
    int n, rep;

    pri=init();

    cout << "Quantos numeros deseja ler?";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << i+1 << "o. valor: ";
        cin >> valor;
        inserir_final(&pri,valor);
    }

    cout << "Lista ligada" << endl;
    imprime(pri);

    rep = repeticao(pri);

    if(rep==1)
        cout << "\nExistem repeticoes.";
    else
        cout << "\nNao existem repeticoes.";

    return 0;
}
