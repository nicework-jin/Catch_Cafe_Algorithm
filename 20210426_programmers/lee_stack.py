from collections import deque
bracket_form_dict = {"(": ")", "{": "}", "[": "]"}

def is_right_form(s):
    stack = []
    for bracket in s:
        if bracket in bracket_form_dict:
            stack.append(bracket)
        elif stack and bracket_form_dict[stack[-1]] == bracket:
            stack.pop()
        else:
            return False
    if not stack:
        return True


def solution(s):
    answer = 0
    s_deque = deque(s)
    for _ in range(len(s)):
        s_deque.append(s_deque.popleft())
        if is_right_form(s_deque):
            answer += 1
    return answer
