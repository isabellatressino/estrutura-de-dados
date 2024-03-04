/* Dada uma lista ligada contendo números inteiros. Construir uma função que troca de lugar o nó armazenado no endereço P com o nó armazenado no endereço S. Sabendose que o nó do endereço P precede o nó de endereço S, na lista ligada. (Não significa que o endereço P é menor do que S). Prever todas as possibilidades, por exemplo: os nós estarem nas pontas, os nós estarem ligados, existirem nós entre eles, existirem
nós antes de P e/ou após S. A troca deverá ser feita, obrigatoriamente, fazendo-se o rearranjo das ligações, não criar novos nós ou mexer com o campo de informação.
(ND4)+*/

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

void trocar_lugar(no**pri, elemento x, elemento y){
    no *p, *noX, *noY;
    p = *pri;
    
}

int main(){

    no *pri;
    elemento valor;
    int P,S;

    pri=init();

    criar_lista(&pri);

    cout << "\nLista ligada" << endl;
    imprime(pri);

    cout << "Escolha dois valores para trocarem de lugar." << endl;
    cout << "Valor 1: ";
    cin >> P;
    cout << "Valor 2: ";
    cin >> S;

    trocar_lugar(&pri,P,S);

    cout << "\nLista ligada" << endl;
    imprime(pri);

    return 0;
}