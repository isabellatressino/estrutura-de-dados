/*Dada uma lista ligada contendo, em cada nó, um caractere referente à uma frase.
Construir uma função que elimina todos os nós que possuem a vogal 'a'. (ND4)*/

#include <iostream>
#include <string.h>
using namespace std;

typedef char elemento;

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
    cout << p->info;
    p = p->link;
  }
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

/********************************************/

void elimina_a(no**pri){
    no *p, *anterior;
    p = *pri;
    while(p != NULL){
        if(p->info == 'a'){
            anterior->link = p->link;
            p = anterior->link;
        }
        else{
            anterior = p;
            p = p->link;
        }
    }
}

int main(){

    no *pri;
    elemento frase[100];

    pri=init();

    cout << "Escreva uma palavra ou pequena frase: ";
    cin.getline(frase,100);
    for(int i=0; i<strlen(frase); i++){
        inserir_final(&pri,frase[i]);
    }

    cout << "\nLista ligada" << endl;
    imprime(pri);

    elimina_a(&pri);

    cout << "\nLista ligada" << endl;
    imprime(pri);

    return 0;
}

/********************************************/