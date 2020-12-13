#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int cnt = 1;
    
    if (s.length() == 1) answer = 1;

    for(int i = 1; i <= s.length()/2; i++) {
        string compressed = "";
        for(int j = 0; j < s.length(); j+=i) {
            string piece = s.substr(j, i); // 글자 조각 추출
            if (j+i > s.length() || s.substr(j+i, i) != piece) { 
                // 범위를 넘거나 다른 글자인 경우
                if (cnt != 1)
                    compressed += to_string(cnt);
                compressed += piece;
                cnt = 1;
            }
            else cnt++; // 같은 글자가 나타나면 압축 횟수 증가
        }
        answer = answer > compressed.length() ? compressed.length() : answer;
    }
    return answer;
}

int main() {
    int result = solution("ababcdcdababcdcd");
    printf("%d\n", result);
    return 0;
}