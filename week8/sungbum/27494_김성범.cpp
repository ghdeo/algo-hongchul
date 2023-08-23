#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;

    for (int i = 2023; i <= n; i++) {
        string num = to_string(i);
        if (num.find('2', 0) != string::npos) {
            int idx = num.find('2', 0);
            if (num.find('0', idx) != string::npos) {
                idx = num.find('0', idx);
                if (num.find('2', idx) != string::npos) {
                    idx = num.find('2', idx);
                    if (num.find('3', idx) != string::npos)
                        ans++;
                }
            }
        }
    }
    cout << ans;
}