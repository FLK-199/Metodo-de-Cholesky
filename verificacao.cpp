#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
int n;

bool simetrica();

int main(){
    //Leitura
    cin >> n;
    A.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    //Verifica se é simétrica
    if(simetrica())
        cout << "e simetrica" << endl;
    else{
        cout << "nao e simetrica" << endl;
        return 0;
    }

    return 0;
}

bool simetrica(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] != A[j][i])
                return false;
        
    return true;
}
