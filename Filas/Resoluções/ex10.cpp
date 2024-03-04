/*Construir uma função que monta uma fila Q, com N elementos, onde cada elemento da fila é um termo da seguinte série:
 1/225 - 2/196 + 4/169 - 8/144 + ....., onde N deve ser lido dentro da função. Declarar como variável local. */

#include <iostream>
using namespace std;

typedef float queue_element;

#include "queue_cf.h"

void popular_fila(Queue& q){
    queue_element v;
    int n;

    cout << "Valor de N: ";
    cin >> n;

    int sup=1,inf=15;

    for(int i=1;i<=n;i++){
        if(i%2 == 0){
            v = (float)-sup/(inf*inf);
            insert(q,v);
        }
        else{
            v = (float)sup/(inf*inf);
            insert(q,v);
        }
        sup *=2;
        inf--;
    }
}

void imprimir(Queue &q){
    Queue aux;
    queue_element v;

    initQueue(aux);

    while(!isEmptyQ(q)){
        v = eliminate(q);
        cout << "   " << v;
        insert(aux,v);
    }

    while(!isEmptyQ(aux))
        insert(q,eliminate(aux));
}

int main(){
    Queue Q;

    initQueue(Q);

    popular_fila(Q);

    imprimir(Q);

    return 0;
}