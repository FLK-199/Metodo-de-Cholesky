import numpy as np
import math

n = int(input())
A = np.zeros((n, n))

for i in range(n):
    A[i] = list(map(float, input().split()))

if np.array_equal(A, A.T):
    print("e simetrica")
else:
    print("nao e simetrica")

if np.all(np.linalg.eigvals(A) > 0):
    print("e definida positiva")
else:
    print("nao e definida positiva")
