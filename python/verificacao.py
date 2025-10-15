import numpy as np
import math

n = int(input())
A = np.zeros((n, n))

for i in range(n):
    A[i] = list(map(float, input().split()))

if np.array_equal(A, A.T):
    print("e simetrica")
    f1 = 0
else:
    print("nao e simetrica")
    f1 = 1

if np.all(np.linalg.eigvals(A) > 0):
    print("e definida positiva")
    f2 = 0
else:
    print("nao e definida positiva")
    f2 = 1

if f1 == 0 and f2 == 0:
    print("pode ser aplicado o metodo de Cholesky")
else:
    print("nao pode ser apicado o metodo de Cholesky")
