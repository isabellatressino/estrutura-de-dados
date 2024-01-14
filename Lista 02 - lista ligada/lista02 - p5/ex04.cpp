/*Dada uma lista ligada contendo números inteiros. Construir uma função que elimina o
nó seguinte à um nó, contendo a informação armazenada num certo X, lido. Se X não
existir na lista ou não existir o nó seguinte ao de X, retornar zero pelo return. Caso
exista X e o seguinte, eliminar o seguinte e retornar 1 pelo return. (ND4)
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

// int elimina_seguinte(no**pri, elemento x){
//     no *p, *anterior = NULL;
//     p = *pri;
//     while (p != NULL && p->info != x){
//         anterior = p;
//         p = p->link;
//     }
//     if(p == NULL || p->link == NULL) return 0;
//     else{
//         anterior = p;
//         p = p->link;
//         anterior->link = p->link;
//         p = anterior->link;
//     }
//     return 1;
// }

int elimina_seguinte(no**pri, elemento x){
    no *p, *seguinte;
    p = *pri;
    while (p != NULL && p->info != x){
        p = p->link;
    }
    if(p == NULL || p->link == NULL) return 0;
    seguinte = p->link;
    p->link = seguinte->link;
    return 1;
}

int main(){

    no *pri;
    elemento valor;
    int ret;

    pri=init();

    criar_lista(&pri);

    cout << "\nLista ligada" << endl;
    imprime(pri);

    
    cout << "\nEscolha o valor anterior ao que deseja eliminar: ";
    cin >> valor;
    
    ret = elimina_seguinte(&pri,valor);

    if(ret == 0) cout << "Erro." << endl;
    else {
        cout << "Sucesso" << endl;
        cout << "\nLista ligada" << endl;
        imprime(pri);
    }

    return 0;
}

/********************************************/