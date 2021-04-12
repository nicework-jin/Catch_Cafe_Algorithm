#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int number = 0, count = 0, remove = 0;
    
    while(true) {
        int len = 0;
        
        if (s.length() == 1) break;
        
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '1') len++; // 길이 체크
            else if (s[i] == '0') remove++; // 제거된 0 의 개수
        }

        number = len;
        count++; // 연산 횟수
        s = "";
        
        while (number > 1) { // 이진법 변환
            if (number % 2 == 1) s += '1';
            else s+= '0';
            number /= 2;
        }
        s += '1';
        reverse(s.begin(), s.end());
    }
    
    answer.push_back(count);
    answer.push_back(remove);
    
    return answer;
}