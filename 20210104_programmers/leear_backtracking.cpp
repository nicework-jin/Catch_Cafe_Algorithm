#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

// 에라토스테네스의 체
bool isPrime(int num)
{
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0) return false;
    return true;
}

int solution(string numbers) {
    vector<bool> prime;
    set<int> s;
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>());
    int maxVal = stoi(numbers);
    prime.resize(maxVal+1, 0);
    sort(numbers.begin(), numbers.end()); // 오름차순

    for(int i = 1; i <= maxVal; i++) // 소수 여부 저장
        prime[i] = isPrime(i);
    
    do {
        for(int i = 1; i <= numbers.size(); i++) {
            int tmp = stoi(numbers.substr(0, i));
            if (prime[tmp])
                s.insert(tmp); // set에 넣어 중복 제거
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    return s.size();
}