from sys import stdin
from collections import deque

MAX, n = 10000, int()
adj = [[] for _ in range(MAX)]
visitados = [False for _ in range(MAX)]
#p = [-1 for _ in range(MAX)]

def bfsAux(u):
    cola = deque()
    cola.append(u)
    visitados[u] = True

    while len(cola) != 0:
        w = cola.popleft()
        print(w)

        for v in adj[w]:
        #for i in range(len(adj[v])):
            #w = adj[w][i]
            if not visitados[v]:
                cola.append(v)
                visitados[v] = True
                #p[v] = v

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
