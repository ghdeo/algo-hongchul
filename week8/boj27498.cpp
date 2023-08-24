#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pair<pii,int>> adj;

int parent[10101];

int find(int x){

    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }

    return parent[x];
}


void nion(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px==py)return;
    parent[py]=px;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N,M;cin>>N>>M;

    for(int i=1;i<=N;i++)parent[i]=i;


    ll sum =0;
    ll total=0;
    for(int i=0;i<M;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        total+=c;
        if(d==1){//MST에 추가
            nion(a,b);
            sum+=c;
        }
        else{//추가안된애들
            adj.push_back({{c,a},b});
        }
    }

    sort(adj.begin(),adj.end(),greater<>());
    
    int adjsz = adj.size();

    for(int i=0;i<adjsz;i++){
        int cost = adj[i].first.first;
        int a = adj[i].first.second;
        int b = adj[i].second;
        if(find(a)!=find(b)){
            nion(a,b);
            sum+=cost;
        }
    }


    cout<<total-sum;
    return 0;
}