#include <string>
#include <vector>
#include <iostream>
#define R first
#define C second
#define ZERO first
#define ONE second

using namespace std;
typedef pair<int, int> Coord;
typedef pair<int, int> Info;
Info Calculation(vector<vector<int>>& arr, int len, Coord c);

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    Info res = Calculation(arr, arr.size(), make_pair(0,0));
    answer.push_back(res.ZERO); answer.push_back(res.ONE);
    return answer;
}

Info Calculation(vector<vector<int>>& arr, int len, Coord c){//len = 격자 단위 크기
    if(len ==  1){//단위 길이(1)
      if(arr[c.R][c.C] == 1){
          return make_pair(0, 1);
      }
      else return make_pair(1, 0);
    } 
    //재귀
    int sub_len = len >> 1;
    vector<Info> sub_res(4);
    Info total_res = make_pair(0, 0);
    //사분면 조사
    for(int i = 0; i < sub_res.size(); i++){
        Coord next_c = c;
        switch(i){
            case 0:
                break;
            case 1:
                next_c.C += sub_len;
                break;
            case 2:
                next_c.R += sub_len;
                break;
            case 3:
                next_c.R += sub_len;
                next_c.C += sub_len;
                break;
        }
        //(0개수, 1개수)계산
        sub_res[i] = Calculation(arr, sub_len, next_c);   
        //합산
        total_res.ZERO += sub_res[i].ZERO; total_res.ONE += sub_res[i].ONE;
    }//사분면 조사
    //사분면 조사//0개수, 1개수 --> 4의 배수인지 체크 --> 4의 배수이면 1개로 통합
    if(total_res.ONE == 0  && total_res.ZERO > 0 && total_res.ZERO % 4 == 0) total_res.ZERO = 1;
    if(total_res.ZERO == 0  && total_res.ONE > 0 &&total_res.ONE % 4 == 0) total_res.ONE = 1;
    //cout << total_res.ZERO << ", " << total_res.ONE <<"\n";
    return total_res;
}
