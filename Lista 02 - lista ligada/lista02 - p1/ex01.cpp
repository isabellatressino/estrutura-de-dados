/*Dada uma lista ligada. Construir uma função que conta o número de nós dessa lista. O
número de nós encontrado deverá retornar pelo comando return. (ND 1)*/

#include <iostream>
using namespace std;

typedef int elemento;
typedef struct no{
    elemento info;
    no *link;
}no;

no* init(){
    return NULL;
}

no* novo_no(){
    no* novo;
    novo = (no*) malloc(sizeof(no));
    if(novo == NULL) exit(1);
    return novo;
}

void inserir_final(no**pri, elemento a){
    no *novo, *p;
    novo = novo_no();
    novo->info = a;
    novo->link = NULL;
    p = *pri;
    while(p!=NULL && p->link!=NULL){
        p = p->link;
    }
    if(p==NULL) *pri = novo;
    else p->link = novo;
}

void imprime(no* pri){
  no* p;
  p = pri;
  while(p != NULL){
    cout << p->info << " ";
    p = p->link;
  }
}

/********************************************/

int numero_nos(no*pri){
    int cont=0;
    no *p; //declarando uma variável para receber o endereço de um nó
    p = pri; //atribuindo à p, o endereço do primeiro nó
    while(p != NULL){ //usado para percorrer a lista ligada até o ultimo elemento
        p = p->link;
        cont ++;
    }
    return cont;
}

int main(){
    no *pri;
    elemento valor;
    int n, num_nos;
    pri = init();

    cout << "Quantos numeros deseja ler?";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << i+1 << "o. valor: ";
        cin >> valor;
        inserir_final(&pri,valor);
    }

    cout << "Lista ligada" << endl;
    imprime(pri);

    num_nos = numero_nos(pri);
    cout << "\nNumero de nos = " << num_nos << endl;

    return 0;
}

/********************************************/