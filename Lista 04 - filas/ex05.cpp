/*Construir uma função que recebe uma fila Q de inteiros, e usando uma estrutura auxiliar inverte a ordem dos elementos da fila.*/

#include <iostream>
#include <time.h>
using namespace std;

typedef int queue_element;
typedef int stack_element;

#include "queue_cf.h"
#include "stack.h"

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

// estrutura auxiliar - pilha
void inverter_ordem(Queue& q){
    Stack P;

    initStack(P);

    while(!isEmptyQ(q)){
        queue_element v = eliminate(q);
        push(P,v);
    }

    while(!isEmpty(P)){
        stack_element v = pop(P);
        insert(q,v);
    }
}

//estrutura auxiliar - vetor
/*void inverter_ordem(Queue& q){
    int aux[100];
    int i=0;

    while(!isEmptyQ(q)){
        queue_element v = eliminate(q);
        aux[i] = v;
        i++;
    }

    for(int j=(i-1); j>=0; j--){
        int v = aux[j];
        insert(q,v);
    }
}*/

int main(){
    Queue Q;

    initQueue(Q);

    popular_fila(Q);

    cout << "\nFila: ";
    imprimir(Q);

    inverter_ordem(Q);

    cout << "\nFila inversa: ";
    imprimir(Q);

    return 0;
}