#include <iostream>
#include <time.h>
#define RESET "\033[0m"
#define RED "\033[31m" 
using namespace std;

typedef int elemento;

typedef struct no{
    elemento info;
    no* link;
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

void imprime(no* pri, int v){
  no* p;
  p = pri;
  while(p != NULL){
    if(p->info == v)
        cout << RED << p->info << " " << RESET;
    else 
        cout << p->info << " ";
    p = p->link;
  }
}

void criar_lista(no** pri){
    no *p = NULL;
    int a = 0,i;
    srand(time(0));
    while(a <= 15){
        i = rand() % 100;
        if (*pri == NULL) {
            *pri = novo_no();
            p = *pri;
            p->info = i;
            p->link = NULL;
        }
        else {
            p->link = novo_no();
            p = p->link;
            p->info = i;
            p->link = NULL;
        }
        a++;
    }
}

void inserir_numero(no**pri, int x, int v){
    no *p, *novo, *posterior;
    p = *pri;
    novo = novo_no();
    novo->info = v;
    novo->link = NULL;
    while(p != NULL){
        if(p->info == x){
            posterior = p->link;
            p->link = novo;
            novo->link = posterior;
        }
        p = p->link;
    }
}

int main(){

    no *pri;
    elemento valor;
    int V,X;

    pri=init();

    criar_lista(&pri);

    cout << "Lista ligada" << endl;
    imprime(pri,-1);

    cout << "\nQual numero deseja inserir? ";
    cin >> V;
    cout << "Apos qual numero? ";
    cin >> X;

    inserir_numero(&pri,X,V);

    cout << "\n\nLista ligada" << endl;
    imprime(pri,V);

    return 0;
}