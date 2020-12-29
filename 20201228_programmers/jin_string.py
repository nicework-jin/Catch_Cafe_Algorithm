import sys
def divider(p):
    u = ''
    curr = 0
    for i in range(len(p)):
        if p[i] == '(':
            curr += 1
        else:  # p[i] == ')'
            curr -= 1
        u += p[i]
        if curr == 0:
            v = p[i + 1:]
            return u, v

def judge(u):
    curr = 0
    for c in u:
        if c == '(':
            curr += 1
        else: # c ==')'
            curr -= 1
        if curr < 0:
            return False
    return True

def solution(p):
    if p == '':
        return p
    else:
        u, v = divider(p)
        if judge(u):
            return u + solution(v)
        return '(' + solution(v) + ')' + ''.join(['(' if x == ')' else ')' for x in u[1:-1]])


if __name__ == '__main__':
    p = ''
    p = '(()())()'
    # p = '())('
    print(solution(p))
    # print(ans)
