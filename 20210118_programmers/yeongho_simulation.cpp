#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int MAXIMUM = -100;
    int MAX = *max_element(citations.begin(), citations.end());
    for(int i = 0; i <= MAX; i++) {
        int up = 0, down = 0;
        
        for(int j = 0; j < citations.size(); j++) {
            if( citations[j] >= i ) up++;
            else if ( citations[j] <= i ) down++;
        }
        
        if( i <= up && citations.size() - up == down ) {
            MAXIMUM = max(MAXIMUM, i);
        }
    }
    
    answer = MAXIMUM;
    return answer;
}
