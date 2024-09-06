"""
Implementación Algoritmo de Bellman-Ford-Moore

"""

"""
G = [[1, 2], [2, 3], [1, 3], []]
w = [[0, 4, 5, float('inf')], [float('inf'), 0, -1, 1], [float('inf'), 2, 0, -1], [float('inf'), float('inf'), float('inf'), float('inf')]]
"""

"""
G = [[1, 2], [2, 3], [3], []]
w = [[0, 5, 3, float('inf')], [float('inf'), 0, -3, 2], [float('inf'), float('inf'), 0, 2], [float('inf'), float('inf'), float('inf'), float('inf')]]
"""

G = [[1, 2], [2, 3], [3, 4], [], [1]]
w = [[0, 5, 3, float('inf'), float('inf')], [float('inf'), 0, -3, 2, float('inf')], [float('inf'), float('inf'), 0, 2, -2], [float('inf'), float('inf'), float('inf'), float('inf'), float('inf')], [float('inf'), 4, float('inf'), float('inf'), 0]]

d, p, ciclo = [], [], []


def bellmanFord(s):
    global d, p
    n, ans = len(G), True
    d = [[float('inf') for _ in range(n)] for _ in range(n)]
    p = [-1 for _ in range(n)]
    
    d[0][s] = 0
    for i in range(1, n):
        for v in range(n):
            d[i][v] = min(d[i][v], d[i - 1][v])
            for u in G[v]:
                if d[i][u] > d[i - 1][v] + w[v][u]:
                    d[i][u] = d[i - 1][v] + w[v][u]
                    p[u] = v

    for v in range(n):
        for u in G[v]:
            if d[n - 1][u] > d[n - 1][v] + w[v][u]:
                ans = False

    return ans

def bellmanFordOpt(s):
    global d, p
    n, ans = len(G), True
    d = [float('inf') for _ in range(n)]
    p = [-1 for _ in range(n)]
    d[s] = 0

    for i in range(1, n):
        for u in range(len(G)):
            for v in G[u]:
                if d[v] > d[u] + w[u][v]:
                    d[v] = d[u] + w[u][v]
                    p[v] = u
                    
    for u in range(len(G)):
        for v in G[u]:
            if d[v] > d[u] + w[u][v]:
                ans = False

    """
    u = 0
    while ans and u < len(G):
        i = 0
        while ans and i < len(G[u]):
            v = G[u][i]
            if d[v] > d[u] + w[u][v]:
                ans = False
            i += 1
        u += 1
    """
    
    return ans

def bellmanFordOpt2(s):
    global d, p
    n, ans, flag = len(G), True, False
    d = [float('inf') for _ in range(n)]
    p = [-1 for _ in range(n)]
    d[s] = 0

    for i in range(1, n):
        flag = False
        for u in range(len(G)):
            for v in G[u]:
                if d[v] > d[u] + w[u][v]:
                    d[v], p[v] = d[u] + w[u][v], u
                    flag = True

        if not flag: break

    if flag:
        for u in range(len(G)):
            for v in G[u]:
                if d[v] > d[u] + w[u][v]:
                    ans = False
    
    return ans

def bellmanFordDetCic(s):
    global d, p, ciclo
    n, ans = len(G), True
    d = [float('inf') for _ in range(n)]
    p = [-1 for _ in range(n)]
    d[s] = 0

    for i in range(1, n):
        t = -1
        for u in range(len(G)):
            for v in G[u]:
                if d[v] > d[u] + w[u][v]:
                    d[v], p[v] = d[u] + w[u][v], u
                    t = v

    if t != -1:
        for i in range(n):
            t = p[t]

        cur, ciclo = t, []
        while cur != t or len(ciclo) == 0:
            ciclo.append(cur)
            cur = p[cur]
        ans = False
    return ans

def main():
    if bellmanFord(0):
        print(d, p)
    else:
        print("El grafo tiene ciclos negativos")
    if bellmanFordOpt(0):
        print(d, p)
    else:
        print("El grafo tiene ciclos negativos")
    if bellmanFordOpt2(0):
        print(d, p)
    else:
        print("El grafo tiene ciclos negativos")

    if bellmanFordDetCic(0):
        print(d, p)
    else:
        print("El grafo tiene ciclos negativos")
        print(ciclo)

main()
