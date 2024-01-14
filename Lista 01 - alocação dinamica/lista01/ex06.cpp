#include <iostream>
#include <iomanip>
#include <cstring>
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

//Funções adicionadas para o Programa 06 -------------------

void acharMenorMaior(produto *p, int n, int *maior, int *menor){
    int max=0, min=999999;
    for(int i=0;i<n;i++){
        if(p[i].preco > max){
            max = p[i].preco;
            (*maior) = i;
        }
        if(p[i].preco < min){
            min = p[i].preco;
            (*menor) = i;
        }
    }
}

int buscarNome(produto *p,int n,char *nm){
    for(int i=0;i<n;i++){
        if(strcmp(p[i].nome,nm)==0){
            return i;
        }
    }
    return -1;
}

void aumentarPreco(produto **p, int n){
    for(int i=0;i<n;i++){
        (*p)[i].preco = 1.1*(*p)[i].preco;
    }
}

int main(){

    produto *prod;
    int N,codigo,posicao,posicao2;

    //Programa 05 -------------------
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

    // //Programa 06 -------------------
    int pmaior, pmenor;
    char nome[31];

    acharMenorMaior(prod,N,&pmaior,&pmenor);
    cout << "\n---- Produto de maior valor ----" << endl;
    imprimirProduto(prod,pmaior);
    cout << "\n---- Produto de menor valor ----" << endl;
    imprimirProduto(prod,pmenor);

    cout << "\nDigite o nome do produto: ";
    cin.ignore();
    cin.getline(nome,30);
    posicao = buscarNome(prod,N,nome);

    if(posicao == -1)
        cout << "Nenhum produto encontrado." << endl;
    else{
        cout << "\n---- Produto Pesquisado ----" << endl;
        imprimirProduto(prod,posicao);
    }

    aumentarPreco(&prod,N);
    cout << "\n---- Lista de Produtos ----" << endl;
    for(int i=0;i<N;i++){
        imprimirProduto(prod,i);
        cout << endl;
    }
    
    free(prod);
    return 0;
}