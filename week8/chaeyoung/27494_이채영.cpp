#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cnt = 0;
    for (int i = 2023; i <= N; i++) {
        string num = to_string(i);
        if (num.find('2', 0) != string::npos) {
            int idx = num.find('2', 0);
            if (num.find('0', idx) != string::npos) {
                idx = num.find('0', idx);
                if (num.find('2', idx) != string::npos) {
                    idx = num.find('2', idx);
                    if (num.find('3', idx) != string::npos)
                        cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}