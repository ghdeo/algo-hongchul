#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;//마지막으로 일하는 날짜
int t[20],p[20];

int dp[20];//i번째 날까지 일해서 벌 수 있는 최대값

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
        dp[i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int cur = t[i]+i-1;cur<=n;cur++){
            int nx = p[i]+dp[i-1];
            if(dp[cur]<nx){
                dp[cur]=nx;
            }
        }
    }

    int ans =0;
    for(int i=1;i<=n;i++){
        if(ans<dp[i])ans=dp[i];
    }
    
    cout<<ans;

    return 0;
}