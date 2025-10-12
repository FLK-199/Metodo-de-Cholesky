#include <bits/stdc++.h>

using namespace std;

#define Matriz vector<vector<int>>

Matriz A, G, Gt;
int n;

int calcula_Gij(int, int);
Matriz transposta(Matriz);
void imprimir(Matriz);

int main(){
    cin >> n;

    A.resize(n, vector<int>(n));
    G.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Matriz A:" << endl;
    imprimir(A);
    cout << endl;

    //Calcula a matriz G
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            G[i][j] = calcula_Gij(i, j);
    
    //Determina Gt
    Gt = transposta(G);

    //imprimi os resultados
    cout << "Matriz G:" << endl;
    imprimir(G);
    cout << endl;

    cout << "Matriz Gt:" << endl;
    imprimir(Gt);
    cout << endl;

    return 0;
}

//Calcula a componente Gij
int calcula_Gij(int i, int j){
    //TODO
    return 0;
}

void imprimir(Matriz mat){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%2d ", mat[i][j]);
        cout << endl;
    }
}

Matriz transposta(Matriz mat){
    Matriz T(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            T[i][j] = mat[j][i];

    return T;
}
