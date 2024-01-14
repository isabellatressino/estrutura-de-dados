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

/*x2 -x +5*/

void criar_lista(Lista &l){
    int n;
    elemento_lista v;

    for(int i=1;i<=31;i++){
        v = (i*i) - i + 5;
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