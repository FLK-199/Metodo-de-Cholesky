#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> A;

bool det(int, int);
bool simetrica();

int main(){
    //Leitura
    cin >> n;
    
    A.resize(n);
    for(auto c : A)
        c.resize(n, 0);

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

    //Verifica se é positiva definida



    return 0;
}

bool det(int i, int j){
    return false;
}

bool simetrica(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] != A[j][i])
                return false;
        }
    }

    return true;
}