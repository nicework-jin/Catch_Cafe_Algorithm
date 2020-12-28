#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 9999; int term_limit = s.length()/2;
    if(s.length() == 1){
        answer = 1; return answer;
    }
    for(int term = 1; term <= term_limit; term++){//문자 자르는 간격
        int s_idx = term; vector<int> pattern_cnt; int cnt = 1;
        string pattern = s.substr(0, term), left_str = "";
        while(true){
            if(s_idx >= s.length()){//시작지점 --> length() 범위 넘어섬
                pattern_cnt.push_back(cnt); 
                s_idx += term; break;
            }
            else if(s_idx + term > s.length()){//시작지점 + 길이 에 해당하는 index가 length 범위를 넘어선다
                pattern_cnt.push_back(cnt);
                left_str = s.substr(s_idx, s.length()-s_idx);
                s_idx += term; break;
            }
            if(pattern.compare(s.substr(s_idx, term)) == 0){//패턴 일치
                cnt++; s_idx += term;
            }
            else{//패턴 불일치
                pattern_cnt.push_back(cnt); 
                pattern = s.substr(s_idx, term); cnt = 1; s_idx += term;
            }
        }
        //test
        //for(int i = 0; i < pattern_cnt.size(); i++){ cout << pattern_cnt[i] << " " ;}; cout << "\n";
        //cout << left_str << "\n";
        int local_res = 0; 
        for(int i = 0; i < pattern_cnt.size(); i++){
            if(pattern_cnt[i] > 1){
                string tmp = to_string(pattern_cnt[i]);
                local_res += (tmp.length() + term);
            }
            else{//길이 = 1
                local_res += term;
            }
        }
        local_res += left_str.length(); //cout << local_res <<"\n";
        answer = min(answer, local_res);
    }
    return answer;
}
