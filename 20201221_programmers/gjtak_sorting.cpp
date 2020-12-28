#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int n1, int n2){
    string str1 = to_string(n1), str2 = to_string(n2);
    if(str1[0] == str2[0]){
        //두 숫자를 서로 붙여서 큰 쪽 비교
       string str_cat1 = str1+str2, str_cat2 = str2+str1;
        if(str_cat1 > str_cat2){
            return true;
        }
        else return false;
    }
    else return str1[0] > str2[0];//1. 맨 앞 숫자가 큰 순
    
}
string solution(vector<int> numbers) {
    string answer = "";
    //0으로만 구성되어 있는 경우 주의
    int cnt = count(numbers.begin(), numbers.end(), 0);
    if(cnt == numbers.size()){
        return "0";
    }
    //조건에 맞게 sorting
    sort(numbers.begin(), numbers.end(), compare);
    //정렬결과를 앞에서 부터 하나씩 붙이기
    for(int i = 0; i < numbers.size(); i++){
        answer += to_string(numbers[i]);
    }
    return answer;
}
