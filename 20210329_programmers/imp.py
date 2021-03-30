import sys

# sys.stdin = open("C:/Users/JIn/PycharmProjects/coding_Test/input.txt", "rt")

class Answer:
    def __init__(self, s):
        self.s = s
        self.numList = []
        self.orderedNumList = []
        self.result = []

    def get_number(self):
        self.s = self.s.split("},")
        for i in range(len(self.s)):
            tmp = self.s[i].replace("{", "")
            if i == len(self.s) - 1:
                tmp = tmp.replace("}", "")
            self.numList.append(list(map(int, tmp.split(","))))
        return self.numList

    def orderByleng(self):
        self.orderedNumList = [0] * len(self.numList)

        for number in self.numList:
            self.orderedNumList[len(number) - 1] = number
        return self.orderedNumList

    def get_result(self):
        self.result = []

        for nums in self.orderedNumList:
            for num in nums:
                if num not in self.result:
                    self.result.append(num)
        return self.result


s = "{{1,2,3},{2,1},{1,2,4,3},{2}}"  # 테스트케이스
answer = Answer(s)
answer.get_number()  # 숫자만 파싱하기
answer.orderByleng()  # 숫자의 길이를 기준으로 정렬하기
result = answer.get_result()  # 답 구하기

