#include <iostream>
#include <cmath>
using namespace std;

int n;
pair<int,int> val[20];
int ans = 0;

void dfs(int day, int sum) {
    if (day == n + 1) {
        ans = max(ans, sum);
    }
    if (day > n) {
        return;
    }
    dfs(day + 1, sum); // 상담 안해
    dfs(day + val[day].first, sum + val[day].second); // 상담해
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i].first >> val[i].second;
    }

    dfs(1, 0);
    cout << ans;
}
