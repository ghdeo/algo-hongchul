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

int a;
int b;
int visit[100 + 1];
int ans = 99999;
vector<int> graph[100 + 1];

void dfs(int s, int d)
{
    if (visit[s])
        return;
    visit[s] = 1;
    if (s == b)
        ans = min(d, ans);
    for (int i = 0; i < graph[s].size(); i++)
        dfs(graph[s][i], d + 1);

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> a >> b;
    int num;
    cin >> num;
    for (int i = 0 ; i < num; i ++)
    {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(a, 0);
    if (ans == 99999)
        cout << -1;
    else
        cout << ans;

    return 0;
}
