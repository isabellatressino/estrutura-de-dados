#include <iostream>
using namespace std;

typedef int elemento_lista;
#include "listaligada.h"

/*
init(L)
inserir(L,v,i),
v = eliminar(L,i),
consultar(L,i),
a = vazia(L),
c = compr(L),
alterar(L,v,i). 
*/

/*Dadas duas listas linear L1 e L2, contendo elementos quaisquer. Supor que a primeira lista comporta ambas. Construir uma função que acrescenta a lista L2 no final da L1*/

void juntar_listas(Lista &l1, Lista &l2){
    elemento_lista v;
    for(int i=1;i<=compr(l2);i++){
        v = consultar(l2,i);
        inserir(l1,v,compr(l1)+1);
    }
}

void criar_lista(Lista &l){
    int n;
    elemento_lista v;

    cout << "Quantos elementos deseja ler? ";
    cin >> n;

    for(int i=1;i<=n;i++){
        cout << "Elemento " << i << ": ";
        cin >> v;
        inserir(l,v,i);
    }
}

void imprimir(Lista &l){
    elemento_lista v;
    for(int i=1;i<=compr(l);i++){
        v = consultar(l,i);
        cout << v << " ";
    }
}

int main(){
    Lista L1, L2;

    init(L1);
    init(L2);

    criar_lista(L1);
    criar_lista(L2);

    cout << "\nLista 1: " << endl;
    imprimir(L1);

    cout << "\nLista 2: " << endl;
    imprimir(L2);

    juntar_listas(L1,L2);
    cout << "\nLista 1 + 2: " << endl;
    imprimir(L1);

    return 0;
}