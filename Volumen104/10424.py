import sys

def calculate(name):
    total = 0
    
    for char in name:
        if 'a' <= char <= 'z':
            total += ord(char) - 96  
        elif 'A' <= char <= 'Z':
            total += ord(char) - 64  
    
    while total >= 10:
        temp = 0
        while total:
            temp += total % 10
            total //= 10
        total = temp
    
    return total

def main():
    input_data = sys.stdin.read().splitlines()  
    i = 0
    total_lines = len(input_data)
    
    while i < total_lines:
        if i + 1 < total_lines:
            name_one = input_data[i].strip()
            name_two = input_data[i + 1].strip()
            
            first = calculate(name_one)
            second = calculate(name_two)

            if first < second:
                print(f"{(first * 100.0 / second):.2f} %")
            else:
                print(f"{(second * 100.0 / first):.2f} %")
        
        i += 2

main()
