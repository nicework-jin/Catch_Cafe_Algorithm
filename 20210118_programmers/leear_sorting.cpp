#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size(); // 총 논문 개수
    int h = 0, maxVal = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int i = 0; i < n; i++) // 최대값 설정
        maxVal = max(maxVal, citations[i]);
        
    while(1) {
        if (h > maxVal) break;
        
        int under = 0, above = 0;
        for(int i = 0; i < n; i++) {
            if (citations[i] >= h) above++;
            else under++;
        }
        if (above >= h) { // h번 이상 인용된 논문이 h편 이상
            answer = max(answer, h);
        }
        h++;
    }
    return answer;
}