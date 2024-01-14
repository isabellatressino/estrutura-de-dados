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

/* Construir uma função que recebe uma lista linear L, com números inteiros, e verifica se os elementos da lista estão em ordem crescente. O resultado deverá retornar através de um return. Na main, imprimir mensagem.*/

int verificar_ordem(Lista &l){
    elemento_lista v,w;
    int i, j;
    for(i=1; i<=compr(l);i++){
        v = consultar(l,i);
        j = i+1;
        for(j=1; j<=compr(l);j++){
            w = consultar(l,j);
            if(v > w) return -1;
        }
    }
    return 0;
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
    Lista L;
    int ret;

    init(L);

    criar_lista(L);

    imprimir(L);

    ret = verificar_ordem(L);
    if(ret == 0) cout << "\n Os elementos estão em ordem crescente.";
    else cout << "\n Os elementos não estão em ordem crescente.";

    return 0;
}