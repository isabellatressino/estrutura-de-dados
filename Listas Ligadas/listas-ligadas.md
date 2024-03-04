# Listas Ligadas

Lista ligada é um tipo de dado não primitivo formada composta por nós, onde cada nó contém um campo de informação (info) e um campo de ligação (link).

A lista ligada é acessada a partir de uma variável que deverá conter o endereço do primeiro nó da lista.

## Estrutura

```cpp
typedef tipo elemento;
typedef struct no{
    elemento info;
    no * link;
} no;

no * pri;
```

## Principais Funções

### Inicialização de lista vazia

```cpp
no* init(){
    return NULL;
}
```

### Novo Nó

```cpp
no *novo_no(){
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo == NULL)
        exit(1);
    return novo;
}
```

### Imprimir

```cpp
void imprime(no* pri){
    no* p;
    p = pri;
    while(p != NULL){
        cout << p->info << “ ”;
        p = p->link;
    }
}

int main(){
    no* pri;
    imprime(pri);
}
```

### Inserir no final da lista

```cpp
void inserir_final(no**pri, elemento a){
    no* novo, *p;
    novo = no_novo();
    novo->info = a;
    novo->link = NULL;
    p = *pri;

    while(p != NULL && p->link != NULL)
        p = p->link;

    if(p==NULL) *pri = novo;
    else p->link = novo;
}

int main(){
    no *pri;
    pri = init();
    elemento valor;
    inserir_final(&pri,valor);
}

```

### Inserir (lista ordenada)

```cpp
void inserir(no**pri, elemento a){
    no *novo, *p, *anterior;
    anterior = NULL;
    novo = novo_no();
    novo->info = a;
    p = *pri;
    while(p!=NULL && a>p->info){
        anterior = p;
        p=p->link;
    }
    if(p == *pri) *pri = novo;
    else anterior->link = novo;
    novo->link = p;
}
int main(){
    no *pri;
    pri = init();
    elemento valor;
    inserir(&pri,valor);
}
```

### Eliminar (lista ordenada)

```cpp
int eliminar(no**pri,elemento a){
    no *p, *anterior=NULL;
    p = *pri;

    while(p!=NULL && p->info != a){
        anterior = p;
        p = p->link;
    }

    if(p==NULL && a < p->info) return 0; // não existe informaçao ou vazia

    if( p == *pri) *pri = p->link;
    else anterior->link = p->link;

    free(p);

    return 1; //sucesso
}
```

### Eliminar

```cpp
int eliminar_desordenada(no**pri, elemento
a){
    no *p, *anterior=NULL;
    if(*pri==NULL) return -1; //lista vazia
    p = *pri;

    while(p!=NULL && p->info != a){
        anterior = p;
        p = p->link;
    }
    if(p==*pri) *pri =
    p->link;
    else anterior->link = p->link;

    free(p);
    return 1; //sucesso
}

int main(){
    no*pri;
    pri = init();
    elemento valor;
    int flag;

    cin >> valor;

    flag = eliminar_desordenada(&pri,valor);

    cout << (flag ? “Sucesso” : “Não
    existe”);

    return 0;
}
```
