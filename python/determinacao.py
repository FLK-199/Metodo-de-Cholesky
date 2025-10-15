import numpy as np
import math

n = int(input())
A = np.zeros((n, n))

for i in range(n):
    A[i] = list(map(float, input().split()))

def imprimir(mat):
    for i in mat:
        print(i)
    print()

def calculo_G(mat): 
    G = np.zeros((n, n))

    for j in range(n):
        for i in range(j, n):
            if i == 0 and j == 0:
                G[0][0] = math.sqrt(A[0][0])
            if i == j:
                soma = sum(G[i][k]**2 for k in range(i))
                G[i][i] = math.sqrt(A[i][i] - soma)
            elif j == 0:
                G[i][0] = A[i][0] / G[0][0]
            else:
                soma = sum(G[i][k] * G[j][k] for k in range(j))
                G[i][j] = (A[i][j] - soma) / G[j][j]

    return G

G = calculo_G(A)
Gt = G.T

print("\nA:")
imprimir(A)
print("G:")
imprimir(G)
print("Gt:")
imprimir(Gt)
