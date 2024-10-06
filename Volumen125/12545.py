def exec(S, T):
    N = len(S)
    
    qt = 0  # Cantidad de '?' en S que deben ser '1'
    qf = 0  # Cantidad de '?' en S que deben ser '0'
    tf = 0  # Cantidad de '1' en S que deben ser '0'
    ft = 0  # Cantidad de '0' en S que deben ser '1'
    a1 = 0  # Número de '1' en S
    b1 = 0  # Número de '1' en T
    
    # num diferencias entre S y T
    for i in range(N):
        if S[i] == '1':
            a1 += 1
        if T[i] == '1':
            b1 += 1
            
        if S[i] == '?':
            if T[i] == '0':
                qf += 1
            elif T[i] == '1':
                qt += 1
        elif S[i] == '1' and T[i] == '0':
            tf += 1
        elif S[i] == '0' and T[i] == '1':
            ft += 1

    # Verificar si es imposible realizar la transformacion
    resultado = 0  
    if a1 > b1:
        resultado = -1
    else:
        # Calcular el numero minimo de movimientos
        resultado = qf + qt + max(tf, ft)
    
    return resultado

def main():
    C = int(input())  # Leer el numero de casos de prueba
    for caso in range(1, C + 1):
        S = input().strip()  # Leer la cadena S
        T = input().strip()  # Leer la cadena T

        resultado = exec(S, T)
        
        # Imprimir el resultado con el formato adecuado
        print(f"Case {caso}: {resultado}")

main()
