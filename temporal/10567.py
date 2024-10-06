
from sys import stdin

def main():
    candidatos= []
    linea = list(stdin.readline())
    querys = int(stdin.readline().strip())
    for _ in range(querys):
        candidates = stdin.readline()
        candidatos.append(candidates)

    linea.sort()
    for i in linea:
        print(i)

main()

