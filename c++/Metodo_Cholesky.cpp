#include <bits/stdc++.h>

using namespace std;

#define Matriz vector<vector<double>>

Matriz A, G, Gt;
vector<double> b, y, x;
int n;

bool positivaDefinida();
bool simetrica();
bool valida(int);
double det(Matriz);
Matriz calculo_G();
Matriz subMatriz(int, int, Matriz);
Matriz transposta(Matriz);
void imprimir(Matriz);
vector<double> calculo_x();
vector<double> calculo_y();

int main(){
    //Leitura
    cin >> n;

    A.resize(n, vector<double>(n));
    G.resize(n, vector<double>(n, 0));
    b.resize(n);
    y.resize(n);
    x.resize(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
    
    //ignora o b #
    cin.ignore();
    string ignora; getline(cin, ignora);

    for(int i = 0; i < n; i++)
        cin >> b[i];

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

    //Verifica se é possível aplicar o metodo de Cholesky
    if(f1 && f2)
        cout << "Pode ser aplicado o metodo de Cholesky" << endl;
    else{
        cout << "Nao pode ser aplicado o metodo de Cholesky" << endl;
        return 0;
    } 
    cout << endl;

    cout << "Matriz A:" << endl;
    imprimir(A);
    cout << endl;

    //Calculo da matriz G
    G = calculo_G();
    
    //Determinação de Gt
    Gt = transposta(G);

    cout << "Matriz G:" << endl;
    imprimir(G);
    cout << endl;

    cout << "Matriz Gt:" << endl;
    imprimir(Gt);
    cout << endl;

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

//Verifica se é positiva definida
bool positivaDefinida(){
    for(int i = 0; i < n; i++)
        if(!valida(i+1))
            return false;
    
    return true;
}

//Verifica se é simétrica
bool simetrica(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] != A[j][i])
                return false;
        
    return true;
}

//Valida se o determinante é positivo
bool valida(int t){
    Matriz M(t, vector<double>(t));

    for(int i = 0; i < t; i++)
        for(int j = 0; j < t; j++)
            M[i][j] = A[i][j];
    
    if(det(M) > 0)
        return true;
    else    
        return false;
}

//Calcula o determinante
double det(Matriz mat){
    double determinante = 0;

    if(mat.size() == 1)
        return mat[0][0];

    for(int j = 0; j < mat.size(); j++){
        if(mat[0][j] != 0)
            determinante += mat[0][j]*pow(-1, j)*det(subMatriz(0, j, mat));
    }    

    return determinante;
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

//Cria uma submatriz sem uma linha e coluna específica
Matriz subMatriz(int linha, int coluna, Matriz mat){
    int tam = mat.size();

    Matriz sub(tam-1, vector<double>(tam-1));

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

//Retorna a transposta de uma matriz
Matriz transposta(Matriz mat){
    Matriz T(n, vector<double>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            T[i][j] = mat[j][i];

    return T;
}

//Imprime uma matriz
void imprimir(Matriz mat){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%4f ", mat[i][j]);
        cout << endl;
    }
}

//Calcula os valores de x
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

//Calcula os valores de "y" (Gt*x)
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

