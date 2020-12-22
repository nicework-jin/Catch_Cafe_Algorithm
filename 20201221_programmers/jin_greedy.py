import sys
from collections import deque

def solution(number, k):
    number = deque(number)
    stack = deque()

    for comp in number:
        while stack and stack[-1] < comp and k > 0:
            deque.pop(stack)
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
