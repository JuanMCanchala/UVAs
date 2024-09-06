
from sys import stdin

def main():
    # representación listas de adyacencia
    G = []
    G.append([1, 2])     # lista ady. 0
    G.append([5, 4, 6])  # lista ady. 1
    G.append([4, 0])     # lista ady. 2
    G.append([4])        # lista ady. 3
    G.append([5])        # lista ady. 4
    G.append([3])        # lista ady. 5
    G.append([0])        # lista ady. 6

    print(G)

    # matrices de adyacencia
    G = []
    G.append([0, 1, 1, 0, 0, 0, 0])
    G.append([0, 0, 0, 0, 1, 1, 1])
    G.append([1, 0, 0, 0, 1, 0, 0])
    G.append([0, 0, 0, 0, 1, 0, 0])
    G.append([0, 0, 0, 0, 0, 1, 0])
    G.append([0, 0, 0, 1, 0, 0, 0])
    G.append([1, 0, 0, 0, 0, 0, 0])

    print(G)

    # lista de aristas
    G = [(0, 1), (0, 2), (1, 5), (1, 4), (1, 6), (2, 4), (2, 0), (3, 4), (4, 5), (5, 3), (6, 0)]
    print(G)
    
    n, m = list(map(int, stdin.readline().split()))
    G = [[] for _ in range(n)]
    for i in range(m):
        u, v = list(map(int, stdin.readline().split()))
        G[u].append(v)

    print(G)

main()
