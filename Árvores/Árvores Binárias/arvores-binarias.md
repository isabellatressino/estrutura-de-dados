# Árvores Binárias

Árvores onde cada nó tem grau menor ou igual a dois.

```cpp
typedef tipo arvb_elemento;

typedef struct no_arvb{
   arvb_elemento info;
   no_arvb *le, *ld;
} no_arvb;
```

Árvore de pesquisa: estando em qualquer nó, seus descendentes à esquerda são menores do que seu valor e, os da direita são maiores.

## Buscar informação

```cpp
int buscar(no_arvb *raiz, arvb_elemento a){
   no_arvb *p;
   p = raiz;
   while(p != NULL){
      if(p->info == A) return 1;
      if(A > p->info) p = p->ld;
      else p = p->le;
   }
   return 0;
}
```

## Inserir informação

```cpp
void inserir(no_arvb **raiz, arvb_elemento a){
   no_arvb *novo;
   novo = novo_no_arvb();
   novo->info = a;

   if(*raiz == NULL){
      *raiz = novo;
      return;
   }

   no_arvb *p;
   p = *raiz;
   while(p != NULL){
      if(a < p->info)
         if(p->le != NULL)
            p = p->le;
         else{
            p->le = novo;
            return;
         }
      else
         if(p->ld != NULL)
            p = p->ld;
         else{
            p->ld = novo;
            return;
         }
   }
}
```

## Novo nó

```cpp
no_arvb* novo_no_arvb(){
   no_arvb* nv;
   nv=(no_arvb*)malloc (sizeof(no_arvb));
   if(nv == NULL){
      cout << “\nErro de alocação”;
      exit(1);
   }
   nv->le = nv_ld = NULL;
   return nv;
}
```

## Percorrendo uma árvore binária

### Pré-ordem

```cpp
void preordem(no_arvb *t){
   if(t != NULL){
      cout << “ ” << t->info;
      preordem (t->le);
      preordem(t->ld);
   }
}
```

### In-ordem

```cpp
void inordem(no_arvb *t){
   if(t != NULL){
      inordem(t->le);
      cout << “ ” << t->info;
      inordem(t->ld);
   }
}
```

## Pós-ordem

```cpp
void inordem(no_arvb *t){
   if(t != NULL){
      posordem(t->le);
      posordem(t->ld);
      cout << “ ” << t->info;
   }
}
```
