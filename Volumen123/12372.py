import sys

def main():
    input = sys.stdin.read
    data = input().splitlines() 
    
    T = int(data[0]) 
    index = 1
    
    for t in range(1, T + 1):
        valid = True
        
        numbers = list(map(int, data[index].split()))
        index += 1
        
        for num in numbers:
            if num > 20:
                valid = False
        
        if not valid:
            print(f"Case {t}: bad")
        else:
            print(f"Case {t}: good")

main()
