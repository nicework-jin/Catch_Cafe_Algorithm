#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer; int limit = (int)sqrt(yellow);
    for(int yr = 1; yr <= limit; yr++){//노랑의 row길이(col보다 작거나 같음)
        if(yellow % yr != 0) continue;
        int yc = yellow / yr;   //노랑의 col
        int area  = ((yr+1)+(yc+1))*2;
        //cout << area<<"\n";
        if(area == brown){//계산했을 때 brown의 개수와 맞다면
            answer.push_back(yc+2); answer.push_back(yr+2);
            break;
        }
    }
    return answer;
}
