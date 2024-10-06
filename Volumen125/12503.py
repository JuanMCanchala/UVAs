import sys

def main():
    der = 1
    izq = -1
    entrada = sys.stdin.read().splitlines()  

    numCasos = int(entrada[0])  
    indice = 1  

    for _ in range(numCasos):
        numLineas = int(entrada[indice]) 
        indice += 1
        instrucciones = []
        posicion = 0 

        for i in range(numLineas):
            instruccion = entrada[indice]
            indice += 1

            if instruccion == "LEFT":
                instrucciones.append(izq) 
                posicion += izq
            elif instruccion == "RIGHT":
                instrucciones.append(der)  
                posicion += der
            else:
                num = int(instruccion.split()[-1]) - 1  
                instrucciones.append(instrucciones[num])  
                posicion += instrucciones[num]

        print(posicion)  

main()
