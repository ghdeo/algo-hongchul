#include <iostream>
using namespace std;

int N,M;
int x;
int parent[205];
int path[1005];

int findParent(int u){

    if(parent[u]==u) return u;
    parent[u] = findParent(parent[u]);
    return parent[u];
}


void merge(int u, int v){
    parent[findParent(u)]=findParent(v);
}


int main(){

    ios_base::sync_with_stdio();
    cin.tie(0);

    cin>>N>>M;

    for(int i=1; i<=N; i++) parent[i]=i;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>x;
            if(x) {
                merge(i,j);
            }
        }
    }

    for(int i=0; i<M; i++) cin>>path[i];

    bool isTrue=true;

    int root = findParent(path[0]);
    for(int i=1; i<M; i++){
        if(root!=findParent(path[i])) {
            isTrue=false;
            break;
        }
    }

    if(isTrue) cout<<"YES";
    else cout<<"NO";

}
