#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
void BackTracking(string numbers, string res, int len, int& cnt, set<int>& prime_list, vector<int>& visited);
bool IsPrime(int n);

int solution(string numbers) {
    int answer = 0; set<int> prime_list;    //찾은 소수 저장(중복 피하기 위해)
    for(int len = 1; len <= numbers.length(); len++){
        int cnt = 0; vector<int> visited(numbers.length(), false);
        string res = "";
        BackTracking(numbers, res, len, cnt, prime_list, visited);
        answer += cnt;
    }
    
    return answer;
}

void BackTracking(string numbers, string res, int len, int& cnt, set<int>& prime_list, vector<int>& visited){
    if(res.length() == len){//원하는 길이에 도달
        int num = stoi(res);    //숫자로 변환
        if(prime_list.find(num) != prime_list.end()) return; //이미 찾은 소수이다
        if(IsPrime(num)){//소수 맞음
            cnt++; prime_list.insert(num);
        }
        return;
    }
    for(int i = 0; i < numbers.length(); i++){
        if(visited[i]) continue;    //이미 사용했다면 pass
        res += numbers[i]; visited[i] = true;
        BackTracking(numbers, res, len, cnt, prime_list, visited);
        res.pop_back(); visited[i] = false;
    }
}

bool IsPrime(int n){
    if(n == 0 || n == 1) return false;//0이나 1은 소수 아님
    int limit = (int)(sqrt((double)n));
    for(int i = 2; i <= limit; i++){
        if(n % i == 0) return false;    //소수 아님
    }
    return true;//소수 맞음
}
