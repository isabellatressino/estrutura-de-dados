/*Construir uma função que cria uma lista com 50 elementos, onde cada elemento da
lista é um termo da seguinte série: 1!/1 - 2!/3 + 3!/5 - 4!/7.... (ND 3)*/

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
    no *p, *novo;
    int a = 1;
    int b = 1;
    int i =0;
    int fat = 1;

    while(i < 50){
        if (*pri == NULL) {
            *pri = novo_no();
            p = *pri;
        }
        else {
            p->link = novo_no();
            p = p->link;
        }
        p->info = (float)(a)/(b);
        p->link = NULL;
        a += 2;
        fat *=b;
        b++;
        i++;
    }
    
}

int main(){

    no *pri;

    pri=init();

    criar_lista(&pri);

    cout << "Lista ligada" << endl;
    imprime(pri);

    return 0;
}