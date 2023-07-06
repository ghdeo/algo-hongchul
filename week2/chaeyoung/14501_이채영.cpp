#include <iostream>
using namespace std;

int N;
int T[16] = {0};
int P[16] = {0};
int dp[16] = {0};

int solution(){
    int  highest= 0;
    
    for(int i = 0; i <= N; i++){
        dp[i] = max(dp[i], highest);
        // 마감일이 퇴사 전인 경우만 보겠다는 뜻
        if(T[i]+i <= N){
            //(상담시작날의 값+끝나는 날 비용)을 더해주는 것과 (기존 값) 중 큰거 선택
            //-> i 번째 날의 상담 진행                  -> i 번째 날의 상담 진행 x
            dp[T[i]+i] = max(dp[i]+P[i], dp[T[i]+i]);
        }
        highest = max(highest, dp[i]);
    }
    return highest;
}

int main(){

    //날짜 수 입력받기
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> T[i] >> P[i];
    }

    int answer = solution();
    cout << answer;
}