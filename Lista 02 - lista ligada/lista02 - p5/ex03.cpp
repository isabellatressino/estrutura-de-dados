/*Dada uma lista ligada contendo números inteiros. Construir uma função que elimina
todos os nós com conteúdo par. (ND3)
*/

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
    while(a <= 7){
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
void elimina_par(no**pri){
    no *p, *anterior = NULL;
    p = *pri;
    while(p != NULL){
        if((p->info)%2 == 0){
            if(anterior != NULL){
                anterior->link = p->link;
                p = anterior->link;
            }
            else{
                anterior = p;
                p = p->link;
                *pri = p;
            }
        }
        else{
            anterior = p;
            p = p->link;
        }
    } 
}

int main(){

    no *pri;

    pri=init();

    criar_lista(&pri);

    cout << "\nLista ligada: " << endl;
    imprime(pri);

    elimina_par(&pri);

    cout << "\nLista ligada sem pares: " << endl;
    imprime(pri);

    return 0;
}
/********************************************/