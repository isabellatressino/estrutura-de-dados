/*Construir uma função que monta uma fila Q, com 30 elementos, onde cada elemento da fila é um termo da seguinte série:
4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + ... . Isto é, o 1º elemento da fila é: 4 , o 2º é: -4/3 e assim por diante.*/

#include <iostream>
#include <iomanip>
using namespace std;

typedef float queue_element;

#include "queue_cf.h"

void popular_fila(Queue& q){

    int num = 1;

    for(int i=1; i<=30; i++){
        if(i%2 == 0){
            queue_element v = (float)(-4)/num;
            insert(q,v);
        }
        else{
            queue_element v = (float)4/num;
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
        cout << "   " << fixed << setprecision(3) << v;
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