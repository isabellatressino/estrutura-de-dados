/*Construir uma função que cria uma lista ligada para conter em cada nó um termo da
seguinte soma: 1/1 + 3/2 + 5/3 + ... + 99/50 (ND 3)*/

#include <iostream>
#include <iomanip>
using namespace std;

typedef float elemento;

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
    cout << fixed << setw(3) << p->info << " ";
    p = p->link;
  }
}

void criar_lista(no** pri){
    no *p = NULL;
    int a=1, b=1;
    while(a <= 99){
        if (*pri == NULL) {
            *pri = novo_no();
            p = *pri;
            p->info = (float)(a)/(b);
            p->link = NULL;
        }
        else {
            p->link = novo_no();
            p = p->link;
            p->info = (float)(a)/(b);
            p->link = NULL;
        }
        a += 2;
        b++;
    }
}

int main(){

    no *pri;
    int n, rep;
    int a,b;

    pri=init();

    criar_lista(&pri);

    cout << "Lista ligada" << endl;
    imprime(pri);

    return 0;
}