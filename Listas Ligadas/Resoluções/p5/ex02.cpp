/*Dada uma lista ligada contendo números inteiros. Construir uma função que elimina o
primeiro nó da lista e coloca no seu lugar o último nó da lista. O último nó deverá ser
"desligado" do final e "ligado" no início. Não gere novo nó e nem troque as
informações entre os nós. Somente faça o rearranjo dos link's. (ND3)*/

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

/********************************************/
int elimina_primeiro(no**pri){
    no *p, *anterior = NULL;
    p = *pri;
    *pri = p->link;

    while(p->link != NULL){
        anterior = p;
        p = p->link;
    }
    p->link = *pri;
    *pri = p;
    anterior->link = NULL;
}

int main(){

    no *pri;

    pri=init();

    criar_lista(&pri);

    cout << "\nLista ligada: " << endl;
    imprime(pri);

    cout << "\nNova lista ligada: " << endl;
    imprime(pri);

    return 0;
}
/********************************************/