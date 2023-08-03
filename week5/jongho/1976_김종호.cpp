#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <cstring>

#define endl "\n"
#define ll long long

int N, M;
using namespace std;
bool graph[200 + 1][200 + 1];
int parent[200 + 1];

int find(int n)
{
    if (n == parent[n])
        return n;
    else 
        return parent[n] = (find(parent[n]));
}

void Union(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x == y)
        return; 
    if (x < y)
        parent[b] = parent[a];
    else
        parent[a] = parent[b];
}

bool isUnion(int a, int b)
{
    int x = find(a);
    int y = find(b);
    return (x == y);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> M;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j])
                Union(i, j);
        }
    }
    bool ans = true;
    int toFind[200 + 1];

    for (int i = 0 ; i < N ; i++)
    {
        // isUnion 해보면서 아닌거 있으면 false 로 바꿔주자
        cin >> toFind[i];
    }

    return 0;
}
