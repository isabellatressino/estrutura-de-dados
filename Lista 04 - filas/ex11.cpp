/*Construir uma função que monta uma fila Q, com 20 elementos, onde cada elemento da fila é um termo da seguinte série:
 1/1³ - 1/3³ + 1/5³ - 1/7³ + 1/9³  */

#include <iostream>
#include <math.h>
using namespace std;

typedef float queue_element;

#include "queue_cf.h"

void popular_fila(Queue& q){
    queue_element v;
    int num = 1;

    for(int i=1;i<=20;i++){
        if(i%2 == 0){
            v = (float)-1/pow(num,3);
            insert(q,v);
        }
        else{
            v = (float)1/pow(num,3);
            insert(q,v);
        }
        num += 2;
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

