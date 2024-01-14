/*Construir uma função que monta uma fila Q, com 30 elementos, onde cada elemento da fila é um termo da seguinte série:
 xº + x¹ /1! + x² / 2! + x³ / 3! + ...., onde x é um valor lido na main e passado na lista de parâmetros. */

#include <iostream>
#include <math.h>
using namespace std;

typedef float queue_element;

#include "queue_cf.h"

void popular_fila(Queue& q, int x){

    int fat = 1;
    int exp = 0;
    int num = 1;

    for(int i=1; i<=30; i++){
        queue_element v = (float)(pow(x,exp) / fat);
        insert(q,v);
        fat = fat * num;
        num++;
        exp++;
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
    int X;

    initQueue(Q);

    cout << "Valor de X: ";
    cin >> X;

    popular_fila(Q,X);

    imprimir(Q);

    return 0;
}

/*
Supondo que x = 2, no terminal sai assim:

1   2   2   1.33333   0.666667   0.266667   0.0888889   0.0253968   0.00634921   0.00141093   0.000282187   5.13067e-005   8.55112e-006   4.24005e-006   1.28106e-005   1.63488e-005   3.26995e-005   -0.000454287   -0.000291779   0.00478183   -0.000498815   -0.00175477   -0.00802407   0.00972644   -0.0216216   0.0161616   -0.0361991   0.0903955   -0.195122   -0.432432

É normal esses números sairem negativos?

*/