#
# Juan Manuel Canchala 
# 8983809
# Carlos Ramirez
# Complejidad: O(n*m+k)
#

""" 
1.En la lectura se leen n lineas hasta encontrar el end of text es decir O(n)
2. Para cada linea recorro caracter por caracter es decir que son n lineas de m caracteres es decir O(n*m)
3. La verificacion de caracteres especiales es constante
4. el calculo de la entropia es donde se calculan las palabras distintas es decir O(K) k siendo la cantidad de palabras distintas
5. creo que la complejidad es O(n*m + k) n siendo el numero de lineas, m siendo el numero de caracteres y k el numero de palabras distintas
Solucion:
Lo que se me ocurre por el momento es:
1. la variable specialCharacters deberia estar fuera del for para que no se reinicie cada que llegue a esa parte del programa (siguio sin ser suficiente)
2. pasar todo a funciones a parte siendo uno el calculo de entropia otro el manejo del diccionario y otro la lectura de la entrada
"""
import math
import sys

#Este si lo puse en un main 
def main():
    cuentaTot = 0 
    dicc = {}  # Diccionario para contar las palabras
    #evision de caracteres especiales
    specialChars = {',', '.', ';', ':', '!', '?', '"', '(', ')', ' ', '\n'}
    

    for linea in sys.stdin: #lectura
        linea = linea.strip() #elimina espacios en blanco al principio y al final
        if linea == "****END_OF_TEXT****": # en teoria tambien tendria que tener un end of input pero como mi for lee hasta el end of text y luego se encuentra con end of input pero no ve de nuevo un end of text creo que lo ignora o mas bien no hace los calculos.
            
            # Calcular y mostrar la entropía
            totalEntropy = 0
            if cuentaTot > 0:
                maxEntropy = math.log10(cuentaTot)
            else:
                maxEntropy = 0

            for palabra, count in dicc.items(): #items es una operacion constante
                totalEntropy += count * (maxEntropy - math.log10(count))
            #ahi que mantener la variable palabra porque item devuelve una tupla asi que si la quito hacer .items falla
            if cuentaTot > 0:
                totalEntropy /= cuentaTot

            if cuentaTot > 0 and maxEntropy > 0:
                relativeEntropy = (totalEntropy / maxEntropy) * 100
            else:
                relativeEntropy = 0
# fin calculos de la entropia

            print(f"{cuentaTot} {totalEntropy:.1f} {relativeEntropy:.0f}")
            #impresion de resultados

            dicc.clear() # hay que limipar el diccionario o sino se distorsiona la salida
            cuentaTot = 0

            #procesamiento de caracteres especiales
        else:
            currentWord = ""
            for char in linea: #itera sobre cada caracter en la linea
                if char not in specialChars: #verificacion de caracteres especiales
                    char = char.lower()  #pasa a minusculas
                    currentWord += char
                elif currentWord:
                    
                    if currentWord in dicc:
                        dicc[currentWord] += 1
                    else:
                        dicc[currentWord] = 1
                    cuentaTot += 1
                    currentWord = ""
            if currentWord:
                
                if currentWord in dicc:
                    dicc[currentWord] += 1
                else:
                    dicc[currentWord] = 1
                cuentaTot += 1
#entre la linea 68 y 80 veo repeticion de codigo tal vez se pueda abreviar esto
main()
