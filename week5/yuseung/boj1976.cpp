#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> edge[202];
vector<int> plan; //max size 1000;
int N; 
int M; 


/*
    도시를 여러번 방문 가능
    도착할 수 있는지 없는지만 판단하면 됨.
    그래프 연결여부만 판단하면 되나?-> no 방문 순서가 있으니까 순서대로 이어져있어야함.

    다음점이 연결되어있는지 확인한다?
*/

bool solve(int st, int ed){//st-ed가 연결되어있는지 확인하는 함수 연결 -> true 비연결 false

    int dist[202];
    fill(dist,dist+N+1,-1);//
    dist[st]=0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto& k : edge[cur]){
            if(dist[k]==-1){
                dist[k]=dist[cur]+1;
                q.push(k);
            }
        }
    }
    if(dist[ed]==-1)return false;
    else return true;
}

//전체 연결을 확인하는 함수
bool solveAll(){
    bool ans = false;
    for(int i=0;i<M-1;i++){
        ans = solve(plan[i],plan[i+1]);
        if(!ans)return false;
        
    }
    if(ans)return true;
    else return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;//도시수
    cin>>M; //여행할 도시 수

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int con;cin>>con;//연결정보
            if(i==j)continue;
            if(con==1){
                edge[i].push_back(j);//i->j로 갈 수 있음
            }
            else continue;            
        }
    }
    for(int i=1;i<=M;i++){
        int tmp; cin>>tmp;
        plan.push_back(tmp);

    }

    bool ans = solveAll();
    if(ans)cout<<"YES";
    else cout<<"NO";

    



    return 0;
}