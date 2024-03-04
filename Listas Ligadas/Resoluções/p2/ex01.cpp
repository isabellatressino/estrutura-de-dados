/* Construir uma função que cria uma lista ligada para conter em cada nó um número
inteiro com a seguinte regra: o 1º elemento deverá ser igual a 1, o 2º é igual ao
primeiro*2, o 3º igual ao segundo *2, e assim por diante. Parar quando o cálculo do
elemento for maior do que 1000. Não inserir o resultado maior do que 1000. (ND 3)*/

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

void criar_lista(no**pri){
    no *p, *novo;
    novo = novo_no();
    novo->info = 1;
    novo->link = NULL;
    *pri = novo;
    p = *pri;
    while(p != NULL && (p->info)*2 <= 1000){
        novo = novo_no();
        novo->info = (p->info)*2;
        novo->link = NULL;
        p->link = novo;
        p = novo;
    }
}

int main(){

    no *pri;
    elemento valor;
    int n, rep;

    pri=init();

    criar_lista(&pri);

    cout << "Lista ligada" << endl;
    imprime(pri);

    return 0;
}