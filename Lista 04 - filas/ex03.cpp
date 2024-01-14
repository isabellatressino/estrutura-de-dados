/*Dada uma fila de inteiros, construir uma função que elimina todos os elementos maiores ou iguais a um valor lido X.*/

#include <iostream>
#include <time.h>
using namespace std;

typedef int queue_element;

#include "queue_lg.h"

//Funções criadas apenas para testar o exercício ------------------------

void popular_fila(Queue& q){
    int n;
    queue_element v;

    srand(time(0));

    cout << "\nQuantos elementos sua lista deve ter? ";
    cin >> n;
    
    for(int i=1; i<=n; i++){
        v = rand() % n + 1;
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

//-----------------------------------------------------------------------

int eliminar(Queue& q, int valor){
    Queue aux;
    queue_element v;

    initQueue(aux);

    if(isEmptyQ(q)) return 1;

    while(!isEmptyQ(q)){
        v = eliminate(q);
        if(v < valor)
            insert(aux,v);
    }

    while(!isEmptyQ(aux))
        insert(q,eliminate(aux));

}

int main(){
    Queue Q;
    int X, ret;

    initQueue(Q);

    popular_fila(Q);

    imprimir(Q);

    cout << "\nDigite o valor de X: ";
    cin >> X;

    ret = eliminar(Q,X);

    cout << endl;
    if(ret == 1) cout << "Fila vazia";
    else imprimir(Q);

    return 0;  

}