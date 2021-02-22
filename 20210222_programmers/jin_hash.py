def solution(clothes):
    types = {}
    for v, k in clothes:
        types[k] = types.get(k, 0) + 1

    cnt = 1
    for _, v in types.items():
        cnt *= v+1
    return cnt-1
