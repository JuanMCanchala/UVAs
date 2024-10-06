def recurse(length, count):
    resultado = 0
    if length == 1:
        resultado = count + 1
    else:
        new_length = 0
        old_length = length

        while length > 0:
            length //= 10
            new_length += 1

        resultado = recurse(new_length, count + 1)
    
    return resultado

def main():
    entrada_terminada = False 
    
    while not entrada_terminada:
        input_str = input().strip()
        
        if input_str[0] == 'E':
            entrada_terminada = True  
        else:
            if len(input_str) == 1 and input_str == '1':
                print(1)
            else:
                print(recurse(len(input_str), 1))

if __name__ == "__main__":
    main()
