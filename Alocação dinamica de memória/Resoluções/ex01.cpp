/*Escreva um programa que crie um vetor dinamico, de reais, de N posições e encontre o menor e o maior elemento. Porem, ao inves de guardar o valor em uma variavel estatica, crie dois ponteiros que apontem para as respectivas posições do vetor dinamico.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    float *Pvet;
    float *Pmaior, *Pmenor;
    int n;

    //Leitura de n
    cout << "Quantos valores deseja ler no vetor? ";
    cin >> n;

    //Alocação dinamica do vetor
    Pvet = (float*) calloc(n,sizeof(float));
    if(Pvet==NULL) exit(1);

    //Alocação dos ponteiros
    Pmaior = (float*) malloc(sizeof(float));
    Pmenor = (float*) malloc(sizeof(float));
    if(Pmaior == NULL || Pmenor == NULL) exit(1);

    //Leitura dos n elementos do vetor
    for(int i=0; i<n; i++){
        cout << "Elemento [" << i << "]: ";
        cin >> Pvet[i];
    }

    //Inicialização
    *Pmaior = Pvet[0];
    *Pmenor = Pvet[0];

    //Descobrindo o maior e menor elemento
    for(int i=0; i<n; i++){
        if(Pvet[i] > *Pmaior)
            *Pmaior = Pvet[i];
        if(Pvet[i] < *Pmenor)
            *Pmenor = Pvet[i];
    }

    //Imprimir vetor
    cout << "\nVetor Lido: " << endl;
    for(int i=0; i<n; i++){
        cout << setw(3) << Pvet[i];
    }

    //Imprimindo maior e menor numero
    cout << "\nMaior numero digitado = " << *Pmaior << endl;
    cout << "Menor numero digitado = " << *Pmenor << endl;

    //Liberando espaço alocado
    free(Pvet);
    free(Pmaior);
    free(Pmenor);

    return 0;
}


/*Estaria certo se eu ao inves de alocar os ponteiros e inicializar no programa anterior, fazer assim:

int main(){

    float *Pvet;
    int n;

    //Leitura de n

    //Alocaçã dinamica do vetor

    //Leitura dos elementos do vetor

    //Inicialização dos ponteiros para a primeira posição do vetor
    float *Pmaior = &Pvet[0];
    float *Pmenor = &Pvet[0];

    /*Encontrar o maior e menor elemento - percorre o vetor, se o elemento for maior que o valor apontado por Pmaior, ele passa a apontar para esse elemento.
    for(int i=0; i<n; i++){
        if(Pvet[i] > *Pmaior)
            Pmaior = &Pvet[i];
        if(Pvet[i] < *Pmenor)
            Pmenor = &Pvet[i];
    }

    //Imprimir vetor

    //Imprimir maior e menor

    free(Pvet);
    free(Pmaior);
    free(Pmenor);
    return 0;
}

*/