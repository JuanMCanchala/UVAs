"""

Implementación Algoritmos Knapsack
Septiembre 6 de 2022

"""

W = [7, 5, 6, 8] #[6, 2, 11, 6, 4] #[6, 3, 4, 7]
B = [6, 2, 5, 4] #[4, 2, 1, 2, 10] #[3, 1, 5, 2]
N = len(W)
M = 15 #20

#solution divide and conquer
def knapsack(m, n):
    ans = None
    if n == 0 or m == 0: ans = 0
    elif W[n - 1] > m: ans = knapsack(m, n - 1)
    else: ans = max(knapsack(m, n - 1), knapsack(m - W[n - 1], n - 1) + B[n - 1])
    return ans

# dp solution with memoization
# N = total de objetos
# M = capacidad de la mochila
# (N + 1) * (M + 1) subproblemas
#
# Complejidad temporal: O(N * M)
# Complejidad espacial: O(N * M)
def knapsackMemo(m, n, mem):
    ans = None
    if (m, n) in mem: ans = mem[(m, n)]
    else:
        if n == 0 or m == 0: ans = 0
        elif W[n - 1] > m: ans = knapsackMemo(m, n - 1, mem)
        else: ans = max(knapsackMemo(m, n - 1, mem), knapsackMemo(m - W[n - 1], n - 1, mem) + B[n - 1])
        mem[(m, n)] = ans
    return ans

# dp solution with tabulation, time O(N * M) mem O(N * M)
def knapsackTab(M, N):
    tab = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
    for n in range(1, N + 1):
        for m in range(1, M + 1):
            if m - W[n - 1] >= 0: tab[n][m] = max(tab[n - 1][m], tab[n - 1][m - W[n - 1]] + B[n - 1])
            else: tab[n][m] = tab[n - 1][m]
    return tab[N][M]

# dp solution with opt. tabulation, time O(N * M) mem O(2M)
def knapsackTabOpt(M, N):
  prev, curr = 0, 1
  tab = [[0 for _ in range(M + 1)] for _ in range(2)]
  for n in range(1, N + 1):
    for m in range(1, M + 1):
      if m - W[n - 1] >= 0: tab[curr][m] = max(tab[prev][m], tab[prev][m - W[n - 1]] + B[n - 1])
      else: tab[curr][m] = tab[prev][m]
    prev, curr = 1 - prev, 1 - curr
  return tab[prev][M]
  
# dp solution with opt. tabulation, time O(N * M) mem O(M)
def knapsackTabOpt2(M, N):
    tab = [0 for _ in range(M + 1)]
    for n in range(1, N + 1):
        for m in range(M, -1, -1):
            if m - W[n - 1] >= 0: tab[m] = max(tab[m], tab[m - W[n - 1]] + B[n - 1])
    return tab[M]

print(knapsack(M, N))
print(knapsackMemo(M, N, dict()))
print(knapsackTab(M, N))
print(knapsackTabOpt(M, N))
print(knapsackTabOpt2(M, N))