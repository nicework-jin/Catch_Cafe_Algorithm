#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <iostream>

using namespace std;
bool IsCorrect(string s);

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++){
        rotate(s.begin(), s.begin()+1, s.end());
        if(IsCorrect(s)) {
            answer++;
        }
        //cout << s << ", answer = " << answer <<"\n";
    }
    
    return answer;
}

bool IsCorrect(string s){
    set<char> open_bracelet = {'(', '[', '{'};
    set<char> close_bracelet = {')', ']', '}'};
    map<char, char> bracelet_pair = {make_pair('(', ')'), make_pair('[', ']'), make_pair('{', '}')};
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(open_bracelet.find(s[i]) != open_bracelet.end()){//여는 괄호임
            st.push(s[i]);
        }
        else if (close_bracelet.find(s[i]) != close_bracelet.end()){//닫는 괄호임
            if (st.empty()) return false;   //비어 있음 -> false
            if (bracelet_pair[st.top()] == s[i]){
                //여는 괄호와 닫는 괄호가 서로 일치 -> true
                st.pop();
            }
            else return false;//여는 괄호와 닫는 괄호가 서로 불일치 ->false
        }
    }
    if (!st.empty()){//스택에 남아 있음
        return false;
    }
    else return true;//남김 없음 -> 올바른 괄호 문자열
}
