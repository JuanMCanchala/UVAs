def main():
    numCasos = int(input().strip()) 
    case = 1  

    while numCasos > 0:
        numSaltos = int(input().strip()) 
        entrada = input().strip()  
        entrada2 = entrada.split()  
        numeros = []  

        for j in entrada2:
            numeros.append(int(j))

        saltosAltos = 0
        saltosBajos = 0

        for i in range(numSaltos - 1):
            if numeros[i] < numeros[i + 1]:
                saltosAltos += 1
            elif numeros[i] > numeros[i + 1]:
                saltosBajos += 1

        print(f"Case {case}: {saltosAltos} {saltosBajos}")

        numCasos -= 1 
        case += 1  

main()
