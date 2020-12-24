import sys

def solution(number, k):
    number = list(number)
    stack = []
    for comp in number:
        while stack and stack[-1] < comp and k > 0:
            stack.pop(-1)
            k -= 1
        else:
            stack.append(comp)

    if k > 0:    # 반례 5321
        stack = list(stack)
        stack = stack[:len(stack)-k]
    return ''.join(stack)

if __name__ == '__main__':
    number = "5321"
    k = 2
    print(solution(number, k))
    
