# Lista Linear

Conjunto de n > 0 nós, 𝑥1, 𝑥2, … , 𝑥𝑛 , cujas propriedades estruturais envolvem somente a posição relativa linear do nó.

## Estrutura

```cpp
typedef tipo Lista;
typedef tipo elemento_lista;
int main(){
    Lista L;
    elemento_lista v;
    int i; //posição
}
```

## Operações

|  Operação   |   Representação    |                           Definição                            |
| :---------: | :----------------: | :------------------------------------------------------------: |
|   Iniciar   |      init(L)       |                       inicia lista vazia                       |
|   Inserir   |   inserir(L,v,i)   |           Insere v na i-ésima posição de uma lista L           |
|  Eliminar   | v = eliminar(L,i)  | elimina e retorna uma informação da i-ésima posição da lista L |
|  Consultar  | v = consultar(L,i) |          retorna a informação da i-ésima posição de L          |
|   Alterar   |   alterar(L,v,i)   |        altera o conteúdo da i-ésima posição da lista L         |
|    Vazia    |    a = vazia(L)    |                       verifica se vazia                        |
| Comprimento |    c = compr(L)    |              verifica o número de elementos de L               |

## Imprimir Lista Linear

```cpp
void impirmir(Lista l){
    int comp = compr(l);
    for(int i=l;i<=comp;i++)
        cout << “ ” << consultar(l,i);
}
```

## Popular Lista

```cpp
void popular_lista(Lista &L){
    int n;
    elemento_lista v;
    cin >> n;

    for(int i=0; i<=n; i++){
        cin >> v;
        inserir(l,v,i);
    }
}
```
