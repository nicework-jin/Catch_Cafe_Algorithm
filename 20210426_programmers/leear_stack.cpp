#include <string>
#include <vector>
#include <stack>

using namespace std;

int check[3];
int answer, idx;
stack<char> order;

string making_new_str(string s) {
    string new_str = "";
    int start = 1;
    
    for(int i = 0; i < s.length(); i++) {
        new_str += s[start % s.length()];
        start++;
    }
    //cout << new_str << "\n";
    return new_str;
}
void checking(string s) {
    bool flag = true;

    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '(') check[0] += 1, order.push('(');
        else if (s[i] == '[') check[1] += 1, order.push('[');
        else if (s[i] == '{') check[2] += 1, order.push('{');
        else if (s[i] == ')') {
            if (order.size() > 0 && order.top() == '(') {
                order.pop();
                check[0] -= 1;
            }
            else flag = false;
        }
        else if (s[i] == ']') {
            if (order.size() > 0 && order.top() == '[') {
                order.pop();
                check[1] -= 1;
            }
            else flag = false;
        }
        else if (s[i] == '}') {
            if (order.size() > 0 && order.top() == '{') {
                order.pop();
                check[2] -= 1;
            }
            else flag = false;
        }

        if (check[0] < 0 || check[1] < 0 || check[2] < 0) {
            flag = false;
            break;
        }
    }
    //cout << "0 : " << check[0] << ", 1 : " << check[1] << ", 2 : " << check[2] ;

    if (flag && check[0] + check[1] + check[2] == 0) answer++;
    check[0] = check[1] = check[2] = 0;
}
int solution(string s) {
    
    string ns = s;
    while (true) {
        if (idx == ns.length()) break; // 회전 끝
        
        if (idx != 0) ns = making_new_str(ns); // 현재 문자열과 인덱스
        checking(ns); // 문자열 확인
        idx++;
    }
    
    return answer;
}