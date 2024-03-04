/*Dada uma lista ligada contendo numeros inteiros. Construir uma função que verifica se a lista está ordenada ou não. Se ordenada retornar 1, senao 0. (ND 1)
*/

#include <iostream>
using namespace std;

typedef int elemento;
typedef struct no{
    elemento info;
    no *link;
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

void imprime(no* pri){
  no* p;
  p = pri;
  while(p != NULL){
    cout << p->info << " ";
    p = p->link;
  }
}

int verificar_ordenada(no*pri){
    no *p, *c;
    p = pri;
    while(p != NULL){
        c = p->link;
        while(c != NULL){
            if(p->info > c->info)  
                return 1;
            c = c->link;
        }
        p = p->link;
    }
    return 0;
}

int main(){

    no *pri;
    elemento valor;
    int n, ret;

    pri=init();

    cout << "Quantos numeros deseja ler?";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << i+1 << "o. valor: ";
        cin >> valor;
        inserir_final(&pri,valor);
    }

    cout << "Lista ligada" << endl;
    imprime(pri);

    ret = verificar_ordenada(pri);

    if(ret==1)
        cout << "\nA lista nao e ordenada";
    else
        cout << "\nA lista e ordenada.";

    return 0;
}
