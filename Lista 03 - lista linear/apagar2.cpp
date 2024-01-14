#include <iostream>
#define tam 3
using namespace std;

typedef struct{
    int cod;
    char descricao[30];
    float preco;
    int qntdd;
}produtos;

typedef produtos elemento_lista;
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

void popular_lista(Lista &l){
    elemento_lista v;
    for(int i=1;i<=tam;i++){
        cout << "\nProduto " << i;
        cout << "\nCodigo: ";
        cin >> v.cod;
        cout << "Descricao: ";
        cin.ignore();
        cin.getline(v.descricao,30);
        cout << "Preco: ";
        cin >> v.preco;
        cout << "Qntdd: ";
        cin >> v.qntdd;
        inserir(l,v,i);
    }
}

void imprimir(Lista l){
    elemento_lista v;
    for(int i=1;i<=compr(l);i++){
        v = consultar(l,i);
        cout << "\nProduto " << i;
        cout << "\nCodigo: " << v.cod << endl;
        cout << "Descricao: " << v.descricao << endl;
        cout << "Preco: " << v.preco << endl;
        cout << "Qntdd: " << v.qntdd << endl;
    }
}

void reorganizarEstoque(Lista &l) {
    int tamanho = compr(l);
    int i = 1;
    
    while (i <= tamanho) {
        elemento_lista v = consultar(l, i);

        if (v.qntdd < 10) {
            // Remove o produto com estoque menor que 10
            elemento_lista removido = v;
            v = consultar(l, tamanho);
            eliminar(l, tamanho);
            inserir(l, v, i);

            // Insere o produto removido no final da lista
            inserir(l, removido, tamanho);
            tamanho--;
        } else {
            i++;
        }
    }
}


int main(){
    Lista L;

    init(L);

    popular_lista(L);

    reorganizarEstoque(L);

    cout << "\n\n\n";
    imprimir(L);

    return 0;
}