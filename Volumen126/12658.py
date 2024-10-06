import sys

def leer_entrada():
    entrada = sys.stdin.read().splitlines()  
    n = int(entrada[0]) 
    matriz = entrada[1:6] 
    return n, matriz

def obtener_numero(submatriz):

    numero_1 = ['.*.', '.*.', '.*.', '.*.', '.*.']
    numero_2 = ['***', '..*', '***', '*..', '***']
    numero_3 = ['***', '..*', '***', '..*', '***']

    ans = 0
    if submatriz == numero_1:
        ans = '1'
    elif submatriz == numero_2:
        ans = '2'
    elif submatriz == numero_3:
        ans = '3'
    return ans


def main():
    n, matriz = leer_entrada()  

    resultado = []
    for i in range(n):
        submatriz = [fila[i*4:i*4+3] for fila in matriz]  
        resultado.append(obtener_numero(submatriz))  

    print(''.join(resultado)) 

main()
