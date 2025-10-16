#include <bits/stdc++.h>

using namespace std;

#define Matriz vector<vector<double>>

Matriz A, G, Gt;
vector<double> b, y, x;
int n;

Matriz calculo_G();
Matriz transposta(Matriz);
void imprimir(Matriz);
vector<double> calculo_y();
vector<double> calculo_x();

int main(){
    cin >> n;

    A.resize(n, vector<double>(n));
    G.resize(n, vector<double>(n, 0));
    b.resize(n);
    y.resize(n);
    x.resize(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    cin.ignore();
    string ignora; getline(cin, ignora);

    for(int i = 0; i < n; i++)
        cin >> b[i];

    //Calculo da matriz G
    G = calculo_G();
    
    //Determinação de Gt
    Gt = transposta(G);

    //Determinação de y
    y = calculo_y();

    //Determinação de x
    x = calculo_x();

    cout << "resultado: " << endl;
    for(int i = 0; i < n; i++)
    cout << "x" << i+1 << " = " << x[i] << endl;
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

vector<double> calculo_y(){
    vector<double> vec(n);

    for(int i = 0; i < n; i++){
        double w = 0.0;

        for(int k = 0; k < i; k++){
            w += G[i][k]*vec[k];
        }

        vec[i] = (b[i] - w)/G[i][i];
    }

    return vec;
}

vector<double> calculo_x(){
    vector<double> vec(n);

    for(int i = n - 1; i >= 0; i--){
        double w = 0.0;

        for(int k = i+1; k < n; k++){
            w += Gt[i][k]*vec[k];
        }

        vec[i] = (y[i] - w)/Gt[i][i];
    }

    return vec;
}

//Retorna a transposta de uma matriz
Matriz transposta(Matriz mat){
    Matriz T(n, vector<double>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            T[i][j] = mat[j][i];

    return T;
}

