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

/* Dadas duas listas linear L1 e L2, ambas contendo números inteiros ordenados. Construir uma função que cria uma terceira lista linear L3 contendo os elementos da interseção de L1 com L2. */

void interceccao(Lista l1, Lista l2, Lista &l3){
    elemento_lista v1, v2;
    int k=1,j;
    for(int i=1;i<=compr(l1);i++){
        v1 = consultar(l1,i);
        for(j=1;j<=compr(l2);j++){
            v2 = consultar(l2,j);
            if(v1 == v2){
                inserir(l3,v1,k);
                k++;
                break;
            }
        }
        j = 1;
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
    Lista L1,L2,L3;

    init(L1);
    init(L2);
    init(L3);

    criar_lista(L1);
    criar_lista(L2);

    cout << "\nLista 1: " << endl;
    imprimir(L1);

    cout << "\nLista 2: " << endl;
    imprimir(L2);

    interceccao(L1, L2, L3);

    cout << "\nInterseccao L1 e L2" << endl;
    imprimir(L3);

    return 0;
}