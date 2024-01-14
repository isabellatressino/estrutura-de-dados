/*Dada uma lista ligada contendo números inteiros. Construir uma função que insere
após cada nó, um novo nó, com a mesma informação dele. No final a lista deverá estar
com todos os valores duplicados. Não usar estruturas auxiliares para a solução, tais
como, vetor ou outra lista ligada. (ND 3)*/

#include <iostream>
#include <time.h>
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

void criar_lista(no** pri){
    no *p = NULL;
    int a = 0,i;
    srand(time(0));
    while(a <= 15){
        i = rand() % 100;
        if (*pri == NULL) {
            *pri = novo_no();
            p = *pri;
            p->info = i;
            p->link = NULL;
        }
        else {
            p->link = novo_no();
            p = p->link;
            p->info = i;
            p->link = NULL;
        }
        a++;
    }
}

void duplicar_no(no**pri){
    no *p, *novo, *posterior;
    p = *pri;
    while(p != NULL){
        novo = novo_no();
        novo->info = p->info;
        posterior = p->link;
        p->link = novo;
        novo->link = posterior;
        p = novo->link;
    }
}

int main(){

    no *pri;
    elemento valor;
    int V,X;

    pri=init();

    criar_lista(&pri);

    cout << "\nLista ligada" << endl;
    imprime(pri);

    duplicar_no(&pri);

    cout << "\n\nLista ligada com elementos duplicados: " << endl;
    imprime(pri);
    return 0;
}