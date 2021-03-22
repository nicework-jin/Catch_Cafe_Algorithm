import sys
sys.stdin = open("C:/Users/JIn/PycharmProjects/coding_Test/input.txt", "rt")


# def printer(x, y, l):
#     for i in range(l):
#         for j in range(l):
#             print(arr[x + i][y + j], end=' ')
#         print()


def checker(x, y, l, arr):
    s = arr[x][y]
    for i in range(l):
        for j in range(l):
            if arr[x + i][y + j] != s:
                return False
    return True


def add_startList(x, y, k, startList):
    startList.append((y, x, k))
    startList.append((y + k, x, k))
    startList.append((y, k + x, k))
    startList.append((y + k, x + k, k))
    return startList


def converter(x, y, k, arr):
    if arr[x][y] == 0:
        v = 3
    else:
        v = 4

    for i in range(k):
        for j in range(k):
            arr[x + i][y + j] = v
    return arr


def find_zero_one(arr, k):
    zero = 0
    one = 0
    for i in range(k):
        for j in range(k):
            if arr[i][j] == 0:
                zero += 1
            else:
                one += 1
    return zero, one


def solution(arr):
    k = len(arr[0])  # 탐색 길이
    startList = [(0, 0, k)]  # (y, x, k)
    zero, one = find_zero_one(arr, k)  # number of zero, one

    while startList:
        y, x, k = startList.pop()
        if checker(x, y, k, arr):
            if arr[x][y] == 0:
                zero -= k * k - 1
            else:
                one -= k * k - 1
            arr = converter(x, y, k, arr)
        else:
            k = k // 2
            if k < 2:
                continue
            startList = add_startList(x, y, k, startList)
    answer = [zero, one]
    return answer


if __name__ == "__main__":
    arr = [[1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 1, 1, 1], [0, 1, 0, 0, 1, 1, 1, 1],
           [0, 0, 0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 1, 0, 0, 1], [0, 0, 0, 0, 1, 1, 1, 1]]
    res = [4, 9]
    solution(arr)
