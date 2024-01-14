/*II - ex 4*/

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

void criar_segunda(no*pri,no**seg){
    no *p, *q;
    int posicao;
    p = pri;
    while(p!= NULL){
        posicao = p->info;
        q = *seg;
        for(int i=1;i<posicao;i++){
            q=q->link;
        }
        (q->info)++;
    }
    p = p->link;
}

int main(){

    no *pri, *seg;
    elemento valor;


    pri=init();
    criar_lista(&pri);

    cout << "\nLista ligada" << endl;
    imprime(pri);

    criar_segunda(pri,&seg);

    cout << "\nLista ligada" << endl;
    imprime(seg);


    return 0;
}