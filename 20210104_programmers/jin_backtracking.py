import itertools


def isPrimeNum(n):
    if n == 0 or n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def solution(numbers):
    nums = list()
    for i in range(1, len(numbers) + 1):
        N = itertools.permutations(numbers, i)
        nums.extend(map(lambda x: int(''.join(x)), N))

    res = 0
    nums = set(nums)
    for num in nums:
        if isPrimeNum(num):
            res += 1
    return res
