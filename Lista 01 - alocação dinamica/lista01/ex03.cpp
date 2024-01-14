#include <iostream>
#include <iomanip>
using namespace std;

void lerVetor(float **v, int *n){
    cout << "Quantas notas? ";
    cin >> *n;
    *v = (float*) calloc(*n,sizeof(float));
    if(*v==NULL) exit(1);
    for(int i=0;i<*n;i++){
        cout << "Nota " << i+1 << ": ";
        cin >> (*v)[i];
    }
}

void acrescentarMeio(float **v, int n){
    float frac;
    for(int i=0;i<n;i++){
        frac = (*v)[i] - int((*v)[i]);
        if(frac == 0.5){
            (*v)[i] += 0.5;
        }
    }
}

void imprimirVetor(float *v, int n){
    for(int i=0;i<n;i++)
        cout << setw(5) << fixed << setprecision(1) << v[i];
}

int main(){

    float *vetor;
    int N;

    lerVetor(&vetor,&N);

    cout << "\n\n-------- Vetor Lido -------- " << endl;
    imprimirVetor(vetor,N);

    acrescentarMeio(&vetor,N);

    cout << "\n\n-------- Vetor Alterado --------" <<endl;
    imprimirVetor(vetor,N);

    free(vetor);
    return 0;
}