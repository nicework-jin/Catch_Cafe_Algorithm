def solution(people, limit):
    answer = 0
    people = sorted(people)
    front = 0
    back = len(people)-1
    while front < back:
        answer += 1
        if people[front] + people[back] <= limit:
            front += 1
        back -= 1
    return answer

if __name__ == '__main__':
    people = [70, 50, 80, 50]
    limit = 100
    print(solution(people, limit))
