# Árvores Gerais

É uma estrutura de dados cujos nós se relacionam de maneira hierárquica.

- Grau do nó: número de subárvores do nó.
- Grau da árvore: grau máximo dos nós.
- Nó folha: é o nó que tem grau zero.

```cpp
#define GR_MAX 6

typedef tipo arv_elemento;
typedef struct no_arv{
    arv_elemento info;
    no_arv* link[GR_MAX];
} no_arv;

int main(){
    no_arv* raiz;
    raiz = NULL;
}
```

## Alocação de um nó

```cpp
no_arv* novo_no_arv(){
   no_arv* nv;
   nv = (no_arv*) malloc (sizeof(no_arv));
   if(nv == NULL){
       cout<<"\n Erro de alocacao!";
       exit(1);
   }
   for(int i=0;i<GR_MAX;i++)
        nv->link[i]=NULL;
   return nv;
}
```

## Percorrer em largura

Usa como auxiliar uma estrutura de pilha.

```cpp
#define GR_MAX 6

typedef tipo arv_elemento;
typedef struct no_arv{
   arv_elemento info;
   no_arv* link[GR_MAX];
} no_arv;

typedef no_arv* queue_element;
#include “queue_lg.h”

void percorrer_largura(no_arv *raiz, int grau){
   queue_element v;
   Queue F;
   initQueue(F);
   if(raiz==NULL) return;
   insert(F, raiz);
   while(!isEmptyQ(F)){
      v=eliminate(F);
      cout << “ ” << v->info;
      for(int i=0; i<grau; i++){
         if(v->link[i] != NULL)
            insert(F,v->link[i]);
         else break;
      }
   }
}
```

## Percorrer em profundidade

Usa uma pilha como como estrutura auxiliar.

```cpp
void inserir_por_nivel(no_arv**raiz, int grau, arv_elemento x){

   queue_element v;
   no_arv* novo;
   Queue F; initQueue(F);

   novo=novo_no_arv();
   novo->info = x;
   if(*raiz == NULL){//raiz vazia
          *raiz=novo;return;
   }
   insert(F,*raiz);
   while(!isEmptyQ(F)){
       v = eliminate(F);
       for(int j=0;j<grau;j++){
           if(v->link[j]== NULL){
               v->link[j] = novo;
               return;}
           else
               insert(F,v->link[j]);
       }
  }
}
```
