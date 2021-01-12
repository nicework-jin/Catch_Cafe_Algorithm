import sys


def solution(name):
    s = name
    r = list()
    
    # 알파벳 올리기/내리기
    for c in s:
        print(ord(c))
        r.append(ord(c) - 65)
    cnt = 0
    for i in r:
        if i <= 13:
            cnt += i
        else:
            cnt += (26 - i)
            
    # 옆으로 이동
    min_movement = len(r) - 1
    for red in range(len(r)):
        blue = red + 1
        while blue < len(r) and r[blue] == 0:
            blue += 1
        center = len(r) + red - blue
        LR, RL = red, len(r) - blue
        min_movement = min(min_movement, center + min(LR, RL))
    return min_movement + cnt

if __name__ == '__main__':
    R = input()
    print(solution(R))
