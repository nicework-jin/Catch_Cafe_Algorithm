#include <string>
#include <vector>

using namespace std;

vector<int> answer;
vector<int> solution(int n) {   
    vector<vector<int> > arr(n+1, vector<int>(n+1));
    int end = (n * (n+1)) / 2; // 마지막 숫자 설정
    int val = 1, direction = 0; // 시작 값과 방향
    int top = 0, bottom = n-1, left = 0, right = 0;
    
    while (val <= end) {
        if (direction == 0) { // 아래로
            for(int i = top; i <= bottom; i++)
                arr[i][left] = val++;
            top++;
            left++;
            direction = 1;
        }
        else if (direction == 1) { // 우측으로
            for(int i = left; i <= bottom-right; i++)
                arr[bottom][i] = val++;
            bottom--;
            direction = 2;
        }
        else if (direction == 2) { // 대각선으로
            for(int i = bottom; i >= top; i--)
                arr[i][i-right] = val++;
            top++;
            right++;
            direction = 0;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    
    return answer;
}

int main() {
    solution(5);

    for(int i = 0; i < answer.size(); i++)
        printf("%d ", answer.at(i));

    return 0;
}