/*Construir uma função que recebe duas filas Q1 e Q2, contendo números inteiros ordenados e constrói uma terceira fila Q3, contendo os elementos da fila Q1 sem os elementos da interseção de Q1 com Q2. */

#include <iostream>
#include <time.h>
using namespace std;

typedef int queue_element;

#include "queue_cf.h"

//Funções criadas apenas para testar o exercício ------------------------

void popular_fila(Queue& q1, Queue& q2){
    queue_element v;

    int n1 = 7;
    int n2 = 5; 

    int v1[n1] = {1,3,4,5,9,12,23,24};
    int v2[n2] = {3,5,9,21,23};
    
    for(int i=0;i<n1;i++){
        v = v1[i];
        insert(q1,v);
    }

    for(int i=0;i<n2;i++){
        v = v2[i];
        insert(q2,v);
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

void construir_fila(Queue& q1, Queue& q2, Queue& q3){
    queue_element v1,v2;
    Queue aux;

    initQueue(aux);

    while(!isEmptyQ(q1)){
        int flag = 0;
        v1 = consult(q1);
        while(!isEmptyQ(q2)){
            v2 = consult(q2);
            if(v1 == v2)
                flag = 1;
            insert(aux,eliminate(q2));
        }

        while(!isEmptyQ(aux))
            insert(q2,eliminate(aux));

        if(flag == 0)
            insert(q3,eliminate(q1));
        else    
            eliminate(q1);
    }

}

int main(){
    Queue Q1, Q2, Q3;

    initQueue(Q1);
    initQueue(Q2);
    initQueue(Q3);

    popular_fila(Q1,Q2);

    cout << "\nQ1: ";
    imprimir(Q1);

    cout << "\nQ2: ";
    imprimir(Q2);

    construir_fila(Q1,Q2,Q3);

    cout << "\nQ3: ";
    imprimir(Q3);

    return 0;
}
