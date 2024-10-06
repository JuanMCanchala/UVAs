def calcular_encendidos(height, length, wantedSize):

    count = height - wantedSize[0]

    for i in range(1, length):
        if wantedSize[i] != height:
            temp = wantedSize[i - 1] - wantedSize[i]
            
            if temp > 0:
                count += temp

    return count

def main():
    entrada_terminada = False  
    
    while not entrada_terminada:
        height, length = map(int, input().split())
        
        if height == 0 and length == 0:
            entrada_terminada = True
        else:
            wantedSize = list(map(int, input().split()))
            
            resultado = calcular_encendidos(height, length, wantedSize)
            
            print(resultado)

main()
