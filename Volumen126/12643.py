import sys

def torneo(N, i, j):
    ronda = 1 
    while i != j:  
        i = (i + 1) // 2  
        j = (j + 1) // 2  
        ronda += 1 
    return ronda - 1  

def main():

    entrada = sys.stdin.read().splitlines()
    
    for caso in entrada:
        N, i, j = map(int, caso.split())
        print(torneo(N, i, j))

main()
