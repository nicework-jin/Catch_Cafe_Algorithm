#include <string>
#include <algorithm>

using namespace std;

int answer, idx;
int calc(char ch) { // 둘 중 최소값
    int cnt = min(ch - 65, 90 - ch + 1);
    return cnt;
}
int solution(string name) {
    string str = "";
    for(int i = 0; i < name.length(); i++)
        str += 'A'; // 기본 문자열

    while(1) {
        answer += calc(name[idx]); // 문자 탐색 횟수
        str[idx] = name[idx];

        if (str == name) return answer;
        
        // 움직인 거리 계산
        int left = idx, lcnt = 0;
        int right = idx, rcnt = 0;

        while(str[left] == name[left]) {
            left--, lcnt++;
            if (left == -1)
                left = name.length() - 1;
        }
        while (str[right] == name[right]) {
            right++, rcnt++;
            if (right == name.length())
                right = 0;
        }

        if (lcnt < rcnt) {
            answer += lcnt;
            idx = left;
        } else {
            answer += rcnt;
            idx = right;
        }
    }
    return answer;
}
int main() {
    int result = solution("BBBAAAB");
    printf("%d\n", result);
    return 0;
}