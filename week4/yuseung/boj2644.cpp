#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int a,b;
int dist[110];

vector<int> edge[110];

void bfs(int st){//st에서 출발하는 점들 배열 최신화

    queue<int> q;
    q.push(st);
    dist[st]=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==b)return;
        for(auto& k : edge[cur]){
            int nx = k;
            if(dist[nx]==-1){
                q.push(nx);
                dist[nx]=dist[cur]+1;
            }
        }
    }
    return ;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    cin>>a>>b;//구해야할 두사람
    int m;cin>>m;    

    for(int i=1;i<=m;i++){
        int x,y;//부모,자식
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    fill(dist,dist+100,-1);
    bfs(a);
    cout<<dist[b];

    return 0;
}