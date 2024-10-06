import sys

MAX_LONG = 56
MAX_ANCHO = 45
MAX_PROF = 25
MAX_SUMA = 125
MAX_PESO = 7

def main():
    entrada = sys.stdin.read().splitlines()  
    numCasos = int(entrada[0])  

    permitidos = 0  

    for i in range(1, numCasos + 1):

        longitud, ancho, profundidad, peso = map(float, entrada[i].split())

        if (longitud <= MAX_LONG and ancho <= MAX_ANCHO and profundidad <= MAX_PROF) or (longitud + ancho + profundidad <= MAX_SUMA):
            if peso <= MAX_PESO:
                print(1)  
                permitidos += 1
            else:
                print(0)  
        else:
            print(0) 

    print(permitidos)

main()
