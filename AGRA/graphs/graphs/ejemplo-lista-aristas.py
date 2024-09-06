from sys import stdin

def main():
    adj = []

    """
    n = int(stdin.readline())

    
    for i in range(n):
        vals = list(map(int, stdin.readline().split()))
        u = vals[0]
        for j in range(u):
            adj.append((i, vals[j + 1]))
    """
    
    m = int(stdin.readline())
    for i in range(m):
        u, v, p = map(int, stdin.readline().split())
        adj.append((u, v, p))

    print("Grafo")
    for i in range(len(adj)):
        #print("%d %d" %(adj[i][0], adj[i][1]))
        print(adj[i])

main()
