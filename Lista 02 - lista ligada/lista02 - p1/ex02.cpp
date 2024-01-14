/*Dada uma lista ordenada contendo inteiros ordenados. Construir uma função que verifica se há algum numero repetido na lista ou não. Caso exista alguma repetição retornar 1, senao retornar 0. (ND 1)*/

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

void inserir(no**pri, elemento a){
    no *novo, *p, *anterior;
    anterior = NULL;
    novo = novo_no();
    novo->info = a;
    p = *pri;
    while(p!=NULL && a>p->info){
        anterior = p;
        p=p->link;
    }
    if(p == *pri) *pri = novo;
    else anterior->link = novo;
    novo->link = p;
}

void imprime(no* pri){
  no* p;
  p = pri;
  while(p != NULL){
    cout << p->info << " ";
    p = p->link;
  }
}

/********************************************/

int repeticao(no* pri){
    no *p, *proximo;
    p = pri;
    while(p != NULL){
        proximo = p->link;
        if(proximo != NULL && p->info == proximo->info){
            return 1;
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
        inserir(&pri,valor);
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