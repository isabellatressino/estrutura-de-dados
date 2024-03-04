/*Dada uma lista ligada contendo em cada nó um caractere referente à uma palavra.
Construir uma função que insere entre cada caractere da palavra, um nó com o caractere '*'. Não usar estruturas auxiliares para a solução, tais como, vetor ou outra
lista ligada. (ND 3)*/

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
    cout << p->info << " ";
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

void inserir_asterisco(no**pri){
    no *p, *novo, *posterior;
    char valor = '*';
    p = *pri;
    while(p != NULL){
        novo = novo_no();
        novo->info = valor;
        novo->link = NULL;
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
    char palavra[] = "Palavra";

    pri=init();

    for(int i = 0; i<strlen(palavra);i++){
        valor = palavra[i];
        inserir_final(&pri,valor);
    }

    cout << "\nLista ligada" << endl;
    imprime(pri);

    inserir_asterisco(&pri);

    cout << "\nLista ligada com *" << endl;
    imprime(pri);

    return 0;
}