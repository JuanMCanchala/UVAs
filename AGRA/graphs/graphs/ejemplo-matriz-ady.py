from sys import stdin

def main():
    adj = [[0 for i in range(10)] for i in range(10)]
    n = int(stdin.readline())

    for i in range(n):
        vals = list(map(int, stdin.readline().split()))
        u = vals[0]
        for j in range(u):
            v = vals[j + 1]
            adj[i][v] = 1

    print("Grafo")
    for i in range(n):
        for j in range(n):
            print("%d" % adj[i][j], end = ' ')
        print("")

main()
