#include <string>
#include <vector>
#include <algorithm>
#define LEFT first
#define RIGHT second
using namespace std;
typedef pair<int, int> Info;
int solution(vector<int> people, int limit) {
    int answer = 0;
    //무게 -> 오름차순 정리
    sort(people.begin(), people.end());
    Info index = make_pair(0, people.size()-1);
    while(index.LEFT < index.RIGHT){//서로 마주보다가 같아지거나 left가 더 오른쪽에 있으면 end
        if(people[index.LEFT] + people[index.RIGHT] <= limit){
            //범위 안에 들어온다.
            answer++;   //가능한 경우의 수 1증가
            people[index.LEFT] = people[index.RIGHT] = -1;  //사용했음 표시
            index.LEFT++; index.RIGHT--;    //인자 갱신
        }
        else{//범위 초과 -> right index를 옮긴다.
            index.RIGHT--;
        }
    }
    //-1이 아닌 값을 가진 경우는 혼자 타야하는 경우
    //0이상의 값을 가진 경우를 세서 answer에 반영
    answer += (people.size() - count(people.begin(), people.end(), -1));
    return answer;
}
