#include <iostream>
#include <iomanip>
using namespace std;


typedef struct{
    int ra;
    char nome[20];
    float nota;
}Aluno;

Aluno* lerAlunos(int *n){
    Aluno *a;

    cout << "Quantidade de alunos: ";
    cin >> *n;

    a = (Aluno*) calloc(*n,sizeof(Aluno*));
    if(a==NULL) exit(1);

    for(int i=0;i<*n;i++){
        cout << "\nAluno " << i+1 << endl;
        cout << "Ra: ";
        cin >> a[i].ra;
        cout << "Nome: ";
        cin.ignore();
        cin.getline(a[i].nome,20);
        cout << "Nota: ";
        cin >> a[i].nota;
    }

    return a;
}

float calcularMedia(Aluno *a, int n){
    float m=0;
    for(int i=0;i<n;i++){
        m += a[i].nota;
    }
    return m/n;
}

void imprimirAlunos(Aluno *a,int n){
    cout << left << setw(10) << "Ra";
    cout << left << setw(24) << "Nome";
    cout << left << setw(5) << "Nota" << endl;
    for(int i=0;i<n;i++){
        cout << setw(10) << a[i].ra ;
        cout << setw(24) << a[i].nome ;
        cout << setw(5) << fixed << setprecision(1) << a[i].nota << endl;
    }
}

int main(){
    Aluno *alunos;
    int N;
    float media=0;

    alunos = lerAlunos(&N);
    media = calcularMedia(alunos,N);
    imprimirAlunos(alunos,N);

    cout << "Media das notas = " << fixed << setprecision(2) << media << endl;

    free(alunos);
    return 0;
}