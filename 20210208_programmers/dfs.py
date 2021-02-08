def solution(numbers, target):
    def DFS(L, sum):
        nonlocal cnt
        if L == len(numbers):
            if sum == target:
                cnt += 1
            return
        else:
            plus = sum + numbers[L]
            DFS(L + 1, plus)
            minus = sum - numbers[L]
            DFS(L + 1, minus)

    cnt = 0
    DFS(0, 0)
    return cnt
