#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
bool IsCorrect(string str){
    stack<char> st; 
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        }
        else{//str[i] == ')'
            if(st.empty()) return false;
            st.pop();
        }
    }
    if(st.empty()) return true;
    else return false;
}
string Sol(string str){
    string u, v; int left_cnt = 0, right_cnt = 0; int s_idx = 0;
    for(int i = 0; i < str.length(); i++){
        u += str[i]; 
        if(str[i] == '(') left_cnt++;
        else right_cnt++;
        if(left_cnt == right_cnt) {
            s_idx = i+1; break;
        }
    }
    if(s_idx < str.length())//적어도 v는 빈문자열은 아님
        v = str.substr(s_idx, str.length() - s_idx);
    //test
    //cout << "before :: ";
    //cout << "u = " << u << ", v = " << v << "\n";
    
    if(IsCorrect(u)){//u는 올바름
        if(v.compare("") != 0)//빈 문자열이 아님
            v = Sol(v);
        //test
        //cout << "after :: ";
        //cout << "u = " << u << ", v = " << v << "\n";
        return u+v;
    }
    else{//u는 올바르지 않음
        string u_temp;
        for(int i = 1; i < u.length()-1; i++){
            if(u[i] == '(') u_temp += ")";
            else u_temp += "(";
        }
        if(v.compare("") != 0)//빈 문자열이 아님
            v = Sol(v);
        u = "(" + v + ")" + u_temp;
        //test
        //cout << "after :: ";
        //cout << "u = " << u << ", v = " << v << "\n";
        return u;
    }
    
    
    //return u+v;
}

string solution(string p) {
    string answer = Sol(p);
    return answer;
}
