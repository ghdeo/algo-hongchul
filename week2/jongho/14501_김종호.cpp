#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <cstring>

#define endl "\n"
#define ll long long

using namespace std;

#define M 15;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int dp[100];
    int n;

    memset(dp, 0, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        int t, p;
        cin >> t >> p ;
        dp[i + t] = max(dp[i + t] , dp[i] + p);
        for (int j = i + t; j < n; j++)
            dp[j] = max(dp[i + t], dp[j]);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++ )
    {
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << ans;


    return 0;
}
