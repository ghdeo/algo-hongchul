#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,x,y;
int visit[101];
int dist[101];
int isCousin=false;
vector<int> v[101];

void bfs(int x){
    visit[x]=1;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            int next=v[node][i];
            if(!visit[next]){
                visit[next]=1;
                dist[next]=dist[node]+1;
                if(next==y){
                    isCousin=true;
                    return;
                }
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y >> m;
    int a,b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(x);
    if(isCousin)
        cout << dist[y];
    else
        cout << -1;

}