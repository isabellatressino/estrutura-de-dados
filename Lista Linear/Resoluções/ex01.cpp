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

/*Construiu uma função que faz a leitura de vários números inteiros e os armazena numa lista linear*/

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
    Lista L;

    init(L);

    criar_lista(L);

    imprimir(L);

    return 0;
}