#include <bits/stdc++.h>

using namespace std;

#define Matriz vector<vector<int>>

Matriz A;
int n;

bool simetrica();
bool positivaDefinida();
bool valida(int);
int det(Matriz);
Matriz subMatriz(int, int, Matriz);

int main(){
    //Leitura
    cin >> n;
    A.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    //Verifica se é simétrica
    bool f1;
    if(simetrica()){
        cout << "e simetrica" << endl;
        f1 = true;
    }
    else{
        cout << "nao e simetrica" << endl;
        f1 = false;
    }

    cout << endl;

    //Verifica se é positiva definida
    bool f2;
    if(positivaDefinida()){
        cout << "e positiva definida" << endl;
        f2 = true;
    }
    else{
        cout << "nao e positiva definida" << endl;
        f2 = false;
    }

    cout << endl;

    if(f1 && f2)
        cout << "Pode ser aplicado o metodo de Cholesky" << endl;
    else
        cout << "Nao pode ser aplicado o metodo de Cholesky" << endl;
    
    return 0;
}

bool simetrica(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] != A[j][i])
                return false;
        
    return true;
}

bool positivaDefinida(){
    for(int i = 0; i < n; i++)
        if(!valida(i+1))
            return false;
    
    return true;
}

bool valida(int t){
    Matriz M(t, vector<int>(t));

    for(int i = 0; i < t; i++)
        for(int j = 0; j < t; j++)
            M[i][j] = A[i][j];
    
    if(det(M) > 0)
        return true;
    else    
        return false;
}

int det(Matriz mat){
    int determinante = 0;

    if(mat.size() == 1)
        return mat[0][0];

    for(int j = 0; j < mat.size(); j++){
        if(mat[0][j] != 0)
            determinante += mat[0][j]*pow(-1, 1+j)*det(subMatriz(0, j, mat));
    }    

    return determinante;
}

Matriz subMatriz(int linha, int coluna, Matriz mat){
    int tam = mat.size();

    Matriz sub(tam-1, vector<int>(tam-1));

    int ni = 0, nj = 0;

    for(int i = 0; i < tam; i++){
        if(i != linha){
            for(int j = 0; j < tam; j++){
                if(j != coluna){
                    sub[ni][nj] = mat[i][j];
                    nj++;
                }   
            }
            ni++;
            nj = 0;
        }
    }

    return sub;
}
