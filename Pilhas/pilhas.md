# Pilhas

Estrutura onde as inserções e eliminações são feitas apenas em uma das extremidades, chamada “topo”. Elas seguem a política LIFO – last in, first out.

## Estrutura

```cpp
typedef tipo Stack;
typedef tipo stack_element;

int main(){
    Stack P;
    stack_element v;
}
```

## Operações

| Operação  | Representação  |                    Definição                    |
| :-------: | :------------: | :---------------------------------------------: |
|  Iniciar  |  initStack(P)  |               inicia pilha vazia                |
|  Inserir  |   push(P,v)    |           insere v no topo da pilha P           |
| Eliminar  |  v = pop(P,v)  | elimina e retorna informação do topo da pilha P |
| Consultar |  v = peek(P)   |          retorna informação da pilha P          |
|   Vazia   | b = isempty(P) |                verifica se vazia                |
