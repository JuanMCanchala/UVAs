from sys import stdin
from collections import deque

MAX, n = 1000, int()
adj = [[0 for _ in range(MAX)] for _ in range(MAX)]
visitados = [False for _ in range(MAX)]
#p = [-1 for _ in range(MAX)]

def bfsAux(v):
    cola = deque()
    cola.append(v)
    visitados[v] = True

    while len(cola) != 0:
        u = cola.popleft()
        print(u)

        for i in range(n):
            if adj[u][i] == 1 and not visitados[i]:
                cola.append(i)
                visitados[i] = True
                #p[i] = v

def bfs():
    for i in range(n):
        visitados[i] = False
        #p[i] = -1
    for i in range(n):
        if not visitados[i]:
            bfsAux(i)

def main():
    global n, visitados, adj
    n, m = list(map(int, stdin.readline().split()))

    for i in range(n):
        vals = list(map(int, stdin.readline().split()))
        u = vals[0]
        for j in range(u):
            v = vals[j + 1]
            adj[i][v] = 1

    print("Grxafo")
    for i in range(n):
        for j in range(n):
            print("%d" % adj[i][j], end = ' ')
        print("")

    print("BFS")
    bfs()
    for i in range(n):
        print(p[i], end = ' ')
    print("")

main()
