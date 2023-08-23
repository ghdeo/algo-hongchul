#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;
int N, S, D, F, B, K;
int visited[MAX];
int policeOffice[MAX];
int cnt[MAX];

queue<int> q;

void bfs(int idx) {
    q.push(idx);

    while (!q.empty()) {
        idx = q.front();
        q.pop();

        int nextB = idx - B;
        int nextF = idx + F;

        if (nextB > 0) {
            if (!policeOffice[nextB] && !visited[nextB]) {
                visited[nextB] = 1;
                q.push(nextB);
                cnt[nextB] = cnt[idx] + 1;
            }
        }

        if (nextF <= N) {
            if (!policeOffice[nextF] && !visited[nextF]) {
                visited[nextF] = 1;
                q.push(nextF);
                cnt[nextF] = cnt[idx] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S >> D >> F >> B >> K;

    int tmp;
    for (int i = 0; i < K; i++) {
        cin >> tmp;
        policeOffice[tmp] = 1;
    }

    cnt[D] = -1;
    bfs(S);
    if (cnt[D] == -1) {
        cout << "BUG FOUND";
    } else {
        cout << cnt[D];
    }
}