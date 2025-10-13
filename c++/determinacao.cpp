#include <bits/stdc++.h>

using namespace std;

#define Matriz vector<vector<double>>

Matriz A, G, Gt;
int n;

Matriz calculo_G();
Matriz transposta(Matriz);
void imprimir(Matriz);

int main(){
    cin >> n;

    A.resize(n, vector<double>(n));
    G.resize(n, vector<double>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Matriz A:" << endl;
    imprimir(A);
    cout << endl;

    //Calculo da matriz G
    G = calculo_G();
    
    //Determinação de Gt
    Gt = transposta(G);

    //Impressão dos resultados
    cout << "Matriz G:" << endl;
    imprimir(G);
    cout << endl;

    cout << "Matriz Gt:" << endl;
    imprimir(Gt);
    cout << endl;

    return 0;
}

//Determina G
Matriz calculo_G(){
    Matriz mat(n, vector<double>(n, 0));
    
    for(int j = 0; j < n; j++){
        for(int i = j; i < n; i++){
            if(i == 0 && j == 0){
                mat[0][0] = sqrt(A[0][0]);
            }
            if(i == j){
                double soma = 0;

                for(int k = 0; k < i; k++)
                    soma += pow(mat[i][k], 2);

                mat[i][i] = sqrt(A[i][i] - soma);
            }
            if(j == 0){
                mat[i][0] = A[i][0]/mat[0][0];
            }
            else{
                double soma = 0;

                for(int k = 0; k < j; k++)
                    soma += mat[i][k]*mat[j][k];

                mat[i][j] = (A[i][j] - soma)/mat[j][j];

            } 
        }
    }

    return mat;
}

//Imprime uma matriz
void imprimir(Matriz mat){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%2.0f ", mat[i][j]);
        cout << endl;
    }
}

//Retorna a transposta de uma matriz
Matriz transposta(Matriz mat){
    Matriz T(n, vector<double>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            T[i][j] = mat[j][i];

    return T;
}
