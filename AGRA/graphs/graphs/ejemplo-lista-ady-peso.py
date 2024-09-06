from sys import stdin

def main():
    adj = [[] for i in range(10000)]
    n = int(stdin.readline())

    for i in range(n):
        vals = list(map(int, stdin.readline().split()))
        u = vals[0]
        j = 0
        while j < 2 * u:
            adj[i].append((vals[j + 1], vals[j + 2]))
            j += 2

    print("Grafo")
    for i in range(n):
        print("Nodo %d:" % i)
        for j in range(len(adj[i])):
            print(adj[i][j], end = ' ')
        print("")

main()
