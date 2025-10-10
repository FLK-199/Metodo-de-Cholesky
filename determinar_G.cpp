#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A, G;
int n;

int main(){
    //Leitura da matriz A
    cin >> n;

    A.resize(n, vector<int>(n));
    G.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            G[i][j] = 0;

    return 0;
}