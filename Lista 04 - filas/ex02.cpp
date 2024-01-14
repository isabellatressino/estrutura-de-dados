/*Dada uma fila Q qualquer. Construir uma função que elimina dessa fila os N primeiros elementos. Prever a possibilidade da fila estar vazia e de não ter N elementos.*/

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

int eliminar(Queue& q, int n){
    Queue aux;
    queue_element v;
    int compr = 0;

    initQueue(aux);

    //contar numero de elementos da fila
    while(!isEmptyQ(q)){
        v = eliminate(q);
        insert(aux,v);
        compr ++;
    }
    while(!isEmptyQ(aux))
        insert(q,eliminate(aux));


    if(isEmptyQ(q))
        return 1;
    else if(n > compr)
        return -1;
    else{
        for(int i=1; i<=n; i++){
            v = eliminate(q);
        }
    }

}

int main(){

    Queue Q;
    int N;

    initQueue(Q);

    popular_fila(Q);

    imprimir(Q);

    cout << "\nQuantos elementos deseja eliminar? ";
    cin >> N;

    int ret = eliminar(Q,N);

    cout << endl;
    if(ret == 1)
        cout << "Fila Vazia";
    else if(ret == -1)
        cout << "Nao existem " << N << " elementos";
    else
        imprimir(Q);

    return 0;

}