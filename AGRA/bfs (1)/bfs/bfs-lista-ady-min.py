from sys import stdin
from collections import deque

MAX, n = 10000, int()
adj = [[] for _ in range(MAX)]
visitados = [False for _ in range(MAX)]

def bfsAux(u, l):
    cola = deque()
    dist = [float("inf") for _ in range(n)]
    cola.append((u, 0))
    dist[u] = 0
    visitados[u] = True
    flag = True

    while flag and len(cola) != 0:
        w, c = cola.popleft()
        print(w)
        if w == l:
            flag = False
        else:
            for v in adj[w]:
                if not visitados[v]:
                    cola.append((v, c + 1))
                    dist[v] = c + 1
                    visitados[v] = True

    print(dist[l])

def bfs():
    for i in range(n):
        visitados[i] = False
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
            adj[i].append(vals[j + 1])

    print("Grafo")
    for i in range(n):
        print("Nodo %d:" % i)
        for j in range(len(adj[i])):
            print("%d" % adj[i][j], end = ' ')
        print("")

    print("BFS")
    bfs()
    for i in range(n):
        print(p[i], end = ' ')
    print("")

main()
