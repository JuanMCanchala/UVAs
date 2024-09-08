def main():
    numCasos = int(input().strip())  
    while numCasos > 0:
        numCasos2 = int(input().strip())  # Leer el numero de estudiantes
        estudiantes = []  

        for _ in range(numCasos2):  
            puntuacion = int(input().strip()) 
            estudiantes.append(puntuacion) 
        
        ans = -1  

        senior = estudiantes[0]  # El primer estudiante es el senior
        for j in range(1, numCasos2):  # Empezar desde el segundo estudiante (juniors)
            diferencia = senior - estudiantes[j]  # Comparar senior con junior
            if diferencia > ans:  # Si la diferencia es mayor, actualizar la respuesta
                ans = diferencia

        print(f"{ans}\n") 

        numCasos -= 1 

main()
