# Filas

Fila é uma lista linear onde as inserções são feitas no final da estrutura e as eliminações no início. Elas seguem o princípio FIFO – first in, first out.

## Estrutura

```cpp
typedef tipo Queue;
typedef tipo queue_element;

int main(){
    Queue Q;
    queue_element v;
}
```

## Operações

| Operação  |  Representação   |               Definição                |
| :-------: | :--------------: | :------------------------------------: |
|  Iniciar  |   initQueue(Q)   |           inicia fila vazia            |
|  Inserir  |   insert(Q,v)    |      insere v no final da fila Q       |
| Eliminar  | v = eliminate(Q) |     elimina v no início da fila Q      |
| Consultar |  v = consult(Q)  | retorna a informação no início da fila |
|   Vazia   | a = isEmptyQ(Q)  |           verifica se vazia            |
