#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = brown/2; i >= 1; i--) {
        for(int j = i; j >= 1; j--) {
            if (i >= j) {
                if (i * j == brown+yellow && brown == i * 2 + j * 2 - 4) {
                    answer.push_back(i);
                    answer.push_back(j);   
                }
            }
        }
    }
    
    return answer;
}