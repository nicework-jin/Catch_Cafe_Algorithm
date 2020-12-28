#include <string>
#include <vector>
#define R first
#define C second

using namespace std;
typedef pair<int, int> COORD;


vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n);
    for(int i =0; i < n; i++){
        triangle[i].resize(n);
    }
    int max_num = (n*(n+1))/2;//최대값
    int num = 1; int row = 0; int col = 0;
    bool is_end = false;
    while(true){//최대값까지 계속 진행
        //down
        while(!(row >= n || triangle[row][col] > 0)){//범위 벗어나거나 숫자가 존재하면 out
            triangle[row][col] = num; 
            if(num == max_num) {//최대값 도달 시 out
                is_end = true; break;   
            }
            num++; row++;
        }
        if(is_end == true) break;
        //row, col 조정
        row--; col++;
        
        //right
        while(!(col >= n || triangle[row][col] > 0)){//범위 벗어나거나 숫자가 존재하면 out
            triangle[row][col] = num; 
            if(num == max_num) {//최대값 도달 시 out
                is_end = true; break;   
            }
            num++; col++;
        }
        if(is_end == true) break;
        //row, col 조정
        col -= 2; row--;    //col은 두칸 뒤로, row은 1줄 올리기
        
        //diagonal
        while(triangle[row][col] == 0){//숫자가 정해지지 않았다면 설정가능
            triangle[row][col] = num; 
            if(num == max_num) {//최대값 도달 시 out
                is_end = true; break;   
            }
            num++; row--; col--;
        }
        if(is_end == true) break;
        //row, col 조정
        row += 2; col++;    //row는 두 줄 아래로, col은 1줄 앞으로
    }
    //결과 저장
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(triangle[i][j] != 0) answer.push_back(triangle[i][j]);
        }
    }
    return answer;
}
