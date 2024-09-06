from sys import stdin
from collections import deque

MAX = 10000
adj = [[] for i in range(MAX)]
visitado = [0 for i in range(MAX)]
pred = [-1 for i in range(MAX)]
d, f = [-1 for _ in range(MAX)], [-1 for _ in range(MAX)]
n, t = int(), 0
topo = deque()
#topo = []

# 0 = no visitado, 1 = visitado pero no completado, 2 = completado
def topoSortAux(v):
    global t, topo
    t += 1
    visitado[v] = 1
    d[v] = t

    for u in adj[v]:
        if visitado[u] == 0:
            pred[u] = v
            topoSortAux(u)
    t += 1
    f[v] = t
    visitado[v] = 2
    topo.appendleft(v)
    #topo.append(v)

def topoSort():
    for i in range(n):
        visitado[i] = 0
        pred[i] = -1

    for i in range(n):
        if visitado[i] == 0:
            topoSortAux(i)

def main():
    global n, topo
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

    print("Ordenamiento Topológico:")
    topoSort()
    print(*topo)
    print(topo)
    #for i in range(n - 1, -1, -1):
        #print("%d" % topo[i], end = ' ')
    #print("")

main()

    
    
