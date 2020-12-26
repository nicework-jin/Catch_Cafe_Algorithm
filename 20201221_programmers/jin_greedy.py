import sys
def solution(numbers):
    numbers = list(map(str, numbers))    
    numbers = sorted(numbers, key=lambda x: x*4, reverse=False)    # 문제 조건에서 numbers 원소는 1000 이하이므로, 최소 4자리가 되도록 함.
    return str(int(''.join(numbers)))

if __name__ == '__main__':
    numbers = [61, 10, 2]
    print(solution(numbers))


