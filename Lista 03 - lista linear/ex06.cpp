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

/*. Construiu uma função que faz a imprime os elementos de uma lista linear de inteiros.*/

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

void eliminar_maior(Lista &l){
    elemento_lista v;
    int maior = -1;
    int i, p;
    for(i = 1; i <= compr(l); i++){
        v = consultar(l, i);
        if(v > maior){
            maior = v;
            p = i;
        }
    }
    eliminar(l, p);
}


int main(){
    Lista L;

    init(L);

    criar_lista(L);

    cout << "\nLista linear" << endl;
    imprimir(L);

    eliminar_maior(L);

    cout << "\nLista linear com maior numero eliminado" << endl;
    imprimir(L);

    return 0;
}