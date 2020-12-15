'''
https://studyprogram.tistory.com/192를 참고하였음.
'''
import sys
sys.stdin = open("C:/Users/JIn/PycharmProjects/codingtest/venv/input.txt", "rt")

def solution(n):
    board = [[0] * i for i in range(1, n + 1)]
    final_num = (n * (n + 1)) // 2  # board에 들어가는 최종 값
    x, y = -1, 0  # board 좌표를 의미
    v = 0  # board 안에 들어갈 값을 의미
    d = [[1, 0], [0, 1], [-1, -1]]  # [[아래로], [오른쪽으로], [대각선 위로]]
    i = 0  # d의 인덱스를 의미

    while True:
        if final_num == v:
            res = []
            for val in board:
                res.extend(val)
            return res

        for _ in range(n):
            x = x + d[i][0]
            y = y + d[i][1]
            v += 1
            board[x][y] = v
        i += 1
        i = i % 3    # d의 범위는 0~3입니다. i는 해당 범위를 순환합니다.
        n -= 1

if __name__ == '__main__':
    n = 4
    print(solution(n))
