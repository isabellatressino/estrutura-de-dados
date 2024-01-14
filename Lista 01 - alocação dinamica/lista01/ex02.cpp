#include <iostream>
#include <iomanip>
using namespace std;


float* ler_vetor(int *n){
    float *v; 
    cout << "Valor de n: ";
    cin >> *n;
    v = (float*) calloc(*n,sizeof(float));
    if(v==NULL) exit(1);
    for(int i=0;i<*n;i++){
        cout << "Elemento [" << i << "]: ";
        cin >> v[i];
    }
    return v;
}

void imprimir_vetor(float *v, int n){
    cout << "Notas lidas: "<< endl;
    for(int i=0;i<n;i++)
        cout << setw(5) << fixed << setprecision(1) << v[i];
}

float acharNota(float *v, int n){
    float *v_aux;
    int *freq;
    int flag,i,j,maior=0,nota;

    v_aux = (float*)calloc(n, sizeof(float));
    freq = (int*)calloc(n, sizeof(int));
    if(v_aux == NULL || freq == NULL ) exit(1);

    for(i=0;i<n;i++){
        flag = 0;
        for(j=0;j<n;j++){
            if(v[i]==v_aux[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            v_aux[i] = v[i];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(v_aux[i]==v[j])
                freq[i]++;
        }
    }
    for(i=0;i<n;i++){ //não consegui supor empate de duas notas
        if(freq[i]>maior){
            maior = i;
        }
    }
    nota = v_aux[maior];
    free(v_aux);
    free(freq);
    return nota;
}

int main(){

    float *vetor;
    float notaMaiorFreq;
    int N;

    vetor = ler_vetor(&N);

    notaMaiorFreq = acharNota(vetor,N);

    imprimir_vetor(vetor,N);

    cout << "\n\nNota de maior frequencia: " << notaMaiorFreq << endl;

    free(vetor);
    return 0;
}