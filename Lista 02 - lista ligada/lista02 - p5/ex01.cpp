/*Dada uma lista ligada contendo números inteiros. Construir uma função que elimina apenas o último nó. Verificar se a lista não está vazia. (ND2)*/

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

//Cria uma função com numeros aleatorios
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
int eliminar_final(no**pri){
    no *p, *anterior;
    if(*pri == NULL) return -1;
    p = *pri;
    while(p->link != NULL){
        anterior = p;
        p = p->link;
    }
    anterior->link = NULL;
    free(p);
    return 0;
}

int main(){

    no *pri;
    int ret;

    pri=init();

    criar_lista(&pri);

    cout << "\nLista ligada" << endl;
    imprime(pri);

    ret = eliminar_final(&pri);
    
    if(ret == -1) cout << "Lista vazia" << endl;
    else{
        cout << "\nLista ligada" << endl;
        imprime(pri);
    }

    return 0;
}
/********************************************/