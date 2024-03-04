# Alocação Dinâmica de Memória

Existem duas maneiras fundamentais de armazenar
informações na memória. A primeira é através de variáveis locais e globais. Mas essas exigem que se tenha conhecimento antecipado da quantidade de memória necessária para a variável, o que nem sempre é possível.

Por isso, existe uma segunda forma, chamada alocação dinâmica. Nesse método, o armazenamento para a informação é alocado da memória livre (heap) para uso em tempo de execução, conforme suas necessidades.

Para solicitar um espaço dessa memoria, é necessário o uso de funções especificas.

## MALLOC()

A função malloc() devolve um ponteiro (endereço) para o início do bloco alocado, caso não haja memoria suficiente no heap para atender à solicitação, a função devolve um
ponteiro nulo.

```cpp
tipo* malloc(num_bytes);
```

Exemplo:

```cpp
int *p;
p = (int*) malloc (sizeof(int));

//caso a alocação não seja bem sucedida
if(p==NULL){
    cout << “\nErro de alocação”;
    exit(1);
}

cout << “Digite um numero inteiro:”;
cin >> *p;

free(p); //libera o espaço alocado
```

## CALLOC()

```cpp
tipo* calloc(size_t nmemb, size_t size);
```

A função calloc() é usada para alocar espaço na memoria para um array de elementos. Ela requer dois argumentos:

- nmemb: número de elementos no array.
- size: tamanho, em bytes, de cada elemento no array.

A diferença entre malloc() e calloc(), é que calloc() inicializa todos os bits da memória alocada com zero.

```cpp
int *vet;
int n,i;

cout << "Numero de elementos do vetor: ";
cin >> n;

vet = (int*) calloc(n,sizeof(int));

if(vet == NULL) exit(1);

for(i=0;i<n;i++){
    cout << i+1 << "o. elemento: ";
    cin >> vet[i];
}

cout << "\n\nValores lidos: " << endl;
for(i=0;i<n;i++){
    cout << " " << vet[i];
    cout << "\n\nEnderecos de vet: " << endl;
}

cout << "\n\nEnderecos de vet: " << endl;
for(i=0;i<n;i++)
    cout << "Endereco de vet[" << i << "] = " << &vet[i] << endl;

return 0;
```

# Alocação Dinâmica em Funções

## POR RETURN

Em uma função, o que é retornado pelo return, refere-se a apenas UMA informação, por isso, não retornamos array.

Mas, se dentro da função for criada uma variável
alocada dinamicamente, podemos passar seu endereço
pelo return e, na main, atribuir para uma variável este endereço.

```cpp
void imprima_vetor(int *v,int n){
    for(int i=0;i<n;i++)
    cout << setw(3) << v[i];
}

int* leia_vetor(int *n){
    int *v_aux;
    cin >> *n;
    v_aux = (int*) calloc(*n,sizeof(int));
    if(v_aux==NULL) exit(1);

    for(int i=0;i<*n;i++)
        cin >> v_aux[i];
    return v_aux;
}

int main(){
    int *vetor;
    int N;
    vetor = leia_vetor(&N);
    imprima_vetor(vetor,N);
    return 0;
}
```

## POR PARÂMETRO

Podemos também, retornar o endereço da alocação dinâmica pela lista de parâmetros. Para isso, precisamos passar o endereço da variável na chamada e colher com ponteiro na função.

```cpp
void leia_vetor(int**v, int *n){
    cin >> *n;
    *v = (int*) calloc(*n,sizeof(int));
    if(*v==NULL) exit(1);
    for(int i=0;i<*n;i++)
        cin >> (*v)[i];
}

int main(){
    int *vetor;
    int N;
    leia_vetor(&vetor,&N);
    imprima_vetor(vetor,N);
    free(vetor);
    return 0;
}
```

