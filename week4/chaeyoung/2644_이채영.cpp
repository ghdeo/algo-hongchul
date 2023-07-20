#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int arr[MAX][MAX] = {0,};
bool visited[MAX] = {0,};
int depth[MAX] = {0,};
int N, M, A, B;
queue<int> q;

void BFS(int k) {
    q.push(k);
    while(!q.empty()){
        k = q.front();
        q.pop();
        for(int i = 1; i <= N; i++){
            if(arr[k][i] != 0 && visited[i] == 0){
                q.push(i);
                visited[i] = true;
                //촌수 누적해서 더하기
                depth[i] = depth[k]+ 1;
            }
        }
    }
}
int main(){
    cin >> N;
    cin >> A >> B;
    cin >> M;
    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    BFS(A);
    if(depth[B] == 0)
        cout << -1;
    else
        cout << depth[B];
}