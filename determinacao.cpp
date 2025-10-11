#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A, G, Gt;
int n;

int calcula_Gij(int, int);
vector<vector<int>> transposta(vector<vector<int>>);

int main(){
    cin >> n;

    A.resize(n, vector<int>(n));
    G.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    //Calcula a matriz G
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            G[i][j] = calcula_Gij(i, j);
    
    //Determina Gt
    Gt = transposta(G);

    //imprimi os resultados
    cout << "Matriz G:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << G[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    cout << "Matriz Gt:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << Gt[i][j] << " ";
        cout << endl;
    }

    return 0;
}

//Calcula a componente Gij
int calcula_Gij(int i, int j){
    //TODO
    return 0;
}

vector<vector<int>> transposta(vector<vector<int>> mat){
    vector<vector<int>> T(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            T[i][j] = mat[j][i];

    return T;
}