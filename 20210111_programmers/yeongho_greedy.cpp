#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

bool isAlla(string name) {
    for(int i = 0; i < name.size(); i++) {
        if( name[i] != 'A') return false;
    }
    return true;
}

int RIGHT(int cur, string &str) {
    int right = 0;    
    int rPos = cur;
    
    while(1) { //right
        if( str[rPos] != 'A' ) {
            break;
        } else {
            rPos++;
            if( rPos > str.size()-1 ) rPos = 0;
            right++;
        } 
    }
    
    return right;      
}

int LEFT(int cur, string &str) {
    int left = 0;
    int lPos = cur;
    while(1) {
        if( str[lPos] != 'A' ) {
            break;
        } else {
            lPos--;
            if( lPos < 0 ) lPos = str.size() -1;
            left++;
        }
    }  
    return left;    
}

int cursor(int cur, string str) { //JAN -> AAA
    int up = abs(str[cur]-'A'); // A -> x
    int dn = abs(str[cur]-'Z') + 1; // Z -> x
    printf("u : %d dn : %d , min : %d\n", up,dn, min(up,dn));
    return min(up,dn);    
}


int solution(string name) {
    int answer = 0;
    
    int cur = 0;

    // string test = "AAN";
    // cout << RIGHT(cur,test) << endl;
    // cout << isAlla(name);
    while( 1 ) {
        
        answer += cursor(cur, name); //최소 방향키 횟수
        cout << "문자 : " << name[cur] << " 현재 인덱스 : "<< cur << " answer : " << answer << endl;
        name[cur] = 'A';
        
        if( isAlla(name) ) break;
        
        int right = RIGHT(cur,name) % name.size();
        int left = LEFT(cur,name) % name.size();
        
        //작은 쪽으로 이동
        if( right <= left ) {
            cur += right;
            if( cur >= name.size() ) cur = cur - name.size();
            answer += right;
        } else if ( right > left ) {
            cur -= left;
            if( cur < 0 ) cur = name.size() + cur;
            answer += left;
        }
        printf("r, l : %d,%d, next pos : %d\n",right,left,cur);     
    }
    // cout << name << endl;
    // cout << "answer : " << answer << endl;
    

    return answer;
}
