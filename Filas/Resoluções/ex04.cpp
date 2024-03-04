/*Dadas duas filas: Q1 e Q2, ambas contendo números inteiros ordenados. Construir uma função que recebe as duas filas e faz a junção das duas gerando uma terceira Fila Q3. Essa terceira fila deverá ter seus elementos ordenados. As duas filas dadas ficarão vazias ao final do processo. */

#include <iostream>
using namespace std;

typedef int queue_element;

#include "queue_cf.h"

//Funções criadas apenas para testar o exercício ------------------------

void popular_fila(Queue& q1, Queue& q2){
    int n;
    queue_element v;

    int v1[7] = {1,3,12,24,25,30,33};
    int v2[5] = {3,7,9,11,26};
    
    for(int i=0;i<7;i++){
        v = v1[i];
        insert(q1,v);
    }

    for(int i=0;i<5;i++){
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

void juntar_filas(Queue& q1, Queue& q2, Queue& q3){
    queue_element v1,v2;

    while(!isEmptyQ(q1) && !isEmptyQ(q2)){

        v1 = consult(q1);
        v2 = consult(q2);

        if(v1 < v2){
            insert(q3,eliminate(q1));
        }
        else{
            insert(q3,eliminate(q2));
        }
    }
    
    while(!isEmptyQ(q1))
        insert(q3,eliminate(q1));

    while(!isEmptyQ(q2))
        insert(q3,eliminate(q2));
}

int main(){
    Queue Q1,Q2,Q3;

    initQueue(Q1);
    initQueue(Q2);
    initQueue(Q3);

    popular_fila(Q1,Q2);

    cout << "\nQ1: ";
    imprimir(Q1);

    cout << "\nQ2: ";
    imprimir(Q2);

    juntar_filas(Q1,Q2,Q3);

    cout << "\nQ3: ";
    imprimir(Q3);

    return 0;
}