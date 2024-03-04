/*Construir uma função que faz a leitura de n numeros inteiros para uma fila*/

#include <iostream>
using namespace std;

typedef int queue_element;

#include "queue_lg.h"

void popular_fila(Queue& q){
    int n;
    queue_element v;

    cout << "Quantos elementos deseja ler? ";
    cin >> n;

    for(int i=1;i<=n;i++){
        cout << "Elemento " << i << ": ";
        cin >> v;
        insert(q,v);
    }
}

void imprimir(Queue& q){
    Queue aux;
    initQueue(aux);
    queue_element v;
    while(!isEmptyQ(q)){
        v = eliminate(q);
        cout << " " << v;
        insert(aux,v);
    }
    while(!isEmptyQ(aux))
        insert(q,eliminate(aux));
}

int main(){

    Queue Q;

    initQueue(Q);

    popular_fila(Q);

    cout << "Fila: ";
    imprimir(Q);

    return 0;

}