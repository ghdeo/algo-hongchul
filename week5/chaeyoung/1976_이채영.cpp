#include <iostream>
#include <algorithm>
using namespace std;

int parent[201];
int N, M;

int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void union_n(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y){
        if(x<y){
            parent[y] = x;
        }else{
            parent[x] = y;
        }
    }
}

void solve(){
    int start, now;
    cin >> start;
    start = find(start);
    for(int i = 1; i < M; i ++){
        cin >> now;
        if(start != find(now)){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int k;
            cin >> k;
            if(k == 1){
                union_n(i, j);
            }
        }
    }
    solve();
}