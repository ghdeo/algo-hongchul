#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <cstring>

#define endl "\n"
#define ll long long

using namespace std;

int N;
int ans[2];
int ary[128][128];

void solve(int n, int x, int y)
{
    if (n == 1)
    {
        ans[ary[y][x]]++;
        return ;
    }
    int find = ary[y][x];
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ary[y + i][x + j] != find)
            {
                solve(n / 2, x, y);
                solve(n / 2, x + n / 2, y);
                solve(n / 2, x, y + n / 2);
                solve(n / 2, x + n / 2, y + n / 2);
                return;
            }
        }
    }
    ans[find] ++;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0 ; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> ary[i][j];
        }
    }
    
    solve(N, 0, 0);
    cout << ans[0] << endl << ans[1];

    return 0;
}
