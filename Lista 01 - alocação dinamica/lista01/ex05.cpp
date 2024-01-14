#include <iostream>
#include <iomanip>
using namespace std;

typedef struct{
    int cod;
    char nome[30];
    float preco;
    int qntdd;
} produto;

void lerProdutos(produto **p, int *n){
    cout << "Quantos podutos? ";
    cin >> *n;
    *p = (produto*) calloc(*n,sizeof(produto));
    if(*p==NULL) exit(1);

    for(int i=0;i<*n;i++){
        cout << "\nProduto " << i+1 << endl;
        cout << "Codigo: ";
        cin >> (*p)[i].cod;
        cout << "Nome: ";
        cin.ignore();
        cin.getline((*p)[i].nome,30);
        cout << "Preco: ";
        cin >> (*p)[i].preco;
        cout << "Quantidade: ";
        cin >> (*p)[i].qntdd;
    }
}

int buscarProduto(produto *p,int n,int c){
    for(int i=0;i<n;i++){
        if(p[i].cod == c)
            return i;
    }
    return -1;
}

void imprimirProduto(produto *p,int posi){
    cout << "Codigo: " << p[posi].cod << endl;
    cout << "Nome: " << p[posi].nome << endl;
    cout << "Preco: RS " << fixed << setprecision(2) << p[posi].preco << endl;
    cout << "Quantidade: " << p[posi].qntdd << endl;
}

int main(){

    produto *prod;
    int N,codigo,posicao;

    lerProdutos(&prod,&N);

    cout << "\n\nDigite o codigo do produto que deseja buscar: ";
    cin >> codigo;
    posicao = buscarProduto(prod,N,codigo);

    if(posicao == -1)
        cout << "Nenhum produto encontrado." << endl;
    else{
        cout << "\n---- Produto Pesquisado ----" << endl;
        imprimirProduto(prod,posicao);
    }
    
    free(prod);
    return 0;
}