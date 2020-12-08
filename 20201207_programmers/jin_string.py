import sys
def solution(s):
    mn = 1001
    # 1 ~ len(s)//2 길이단위로 나누어 문자열 압축을 진행합니다.
    for i in range(1, len(s)//2+1):
        tmp_s = ''    # 압축 문자열을 담습니다.
        comp = s[0:i]
        k = i
        while k < len(s):
            cnt = 1
            while comp == s[k:k+i]:
                cnt += 1
                k += i
            # 중복이 발생된 문자는 2aa로 tmp_s에 담습니다. cnt는 2aa에서 2에 해당합니다.
            if cnt > 1:
                tmp_s += str(cnt)+comp
            # 중복이 발생되지 않은 문자는 comp의 원형 그대로 tmp_s에 담습니다.
            else:
                tmp_s += comp
            comp = s[k:k+i]
            k += i
        # 가장 짧은 문자열의 길이로 갱신합니다.
        if mn > len(tmp_s+s[k-i:]):
            mn = len(tmp_s+s[k-i:])
    return mn

if __name__ == '__main__':
    S = "xababcdcdababcdcd"
    print(solution(S))