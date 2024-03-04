/*Dada uma lista ligada contendo numeros inteitos. Construir uma função que verifica qual o numero que se repete mais vezes nessa lista. Retornar a porcentagem de repetições desse numero em relação a lista toda. (ND 3)*/

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

float verificar_rep(no*pri){
    no *p, *q;
    int cont=0;
    int maior_cont=0;
    int tam_lista=0;

    p = pri;

    if(pri == NULL) return -1;

    while(p != NULL){
        q = pri;
        while(q != NULL){
            if(p->info == q->info){
                cont++;
            }
            q = q->link;
        }
        if(cont > maior_cont){
            maior_cont = cont;
        }
        p = p->link;
        tam_lista ++;
        cont = 0;
    }

    float porcentagem = (float)maior_cont/tam_lista;

    return porcentagem*100;
}

int main(){

    no *pri;
    int n;
    elemento valor;
    float porcentagem;

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

    porcentagem = verificar_rep(pri);

    cout << "\nPorcentagem de repeticoes: " << porcentagem << " % " << endl;

    return 0;
}
