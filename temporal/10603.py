
#
#Fill
#https://uva.onlinejudge.org/external/106/10603.pdf
#

from sys import stdin
from heapq import heappop, heappush

def main():
    casos = int(stdin.readline())
    while casos > 0:
        vals = list(map(int, stdin.readline().split()))
        d, vals = vals[3], vals[:len(vals) - 1]
        cola = [[0, 0, 0, vals[2]]] # costo, a, b, c        
        res, costoRes, flag = d, 0, False
        visitados = {(0, 0, vals[2])}

        while len(cola) != 0:
            curr = heappop(cola)

            for i in range(3):
                if d > curr[i + 1] and d - curr[i + 1] < res:
                    res, costoRes = d - curr[i + 1], curr[0]

            if curr[1] == d or curr[2] == d or curr[3] == d:
                flag = True
                break

            for i in range(3):
                if curr[i + 1] > 0:
                    for j in range(3):
                        oth = list(curr)
                        if i != j:
                            aux = min(curr[i + 1], vals[j] - curr[j + 1])
                            oth[i + 1] = curr[i + 1] - aux
                            oth[j + 1] = curr[j + 1] + aux
                            oth[0] = curr[0] + aux

                            if not (oth[1], oth[2], oth[3]) in visitados:
                                visitados.add((oth[1], oth[2], oth[3]))
                                heappush(cola, oth)

        if flag: print("%d %d" % (curr[0], d))
        else: print("%d %d" % (costoRes, d - res))
        casos -= 1

main()