#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int r = 0, l = people.size() - 1;
    sort(people.begin(), people.end(), greater<>());
    
    while(1) {
        if( r == l ) {
            answer++;
            break;
        } else if ( r > l ) break;
        
        int sum = people[r] + people[l];
        if( sum > limit ) {
            r++; 
            answer++;
        } else if ( sum <= limit) {
            r++;
            l--;
            answer++;
        }
    }
    return answer;
}
