#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int N, M;
char c;
deque<char> q;
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> M;
        if (M == 1) {
            cin >> c;
            q.push_back(c);
            s.push(1);
        }
        else if (M == 2) {
            cin >> c;
            q.push_front(c);
            s.push(0);
        }
        else if (M == 3) {
            if (s.empty()) {
                continue;
            }

            if (s.top()==0) {
                q.pop_front();
            }
            else {
                q.pop_back();
            }
            s.pop();
        }
    }

    if (q.empty()) {
        cout << "0\n";
    }
    else {
        while (!q.empty()) {
            cout << q.front();
            q.pop_front();
        };
        cout << "\n";
    }
    return 0;
}