#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    deque<char> dq;
    stack<int> st;
    int input;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == 1) {
            char c;
            cin >> c;
            dq.push_back(c);
            st.push(1);
        } else if (input == 2) {
            char c;
            cin >> c;
            dq.push_front(c);
            st.push(2);
        } else if (input == 3) {
            if (st.empty()) {
                continue;
            }
            int front = st.top();
            st.pop();
            if (front == 1) {
                dq.pop_back();
            } else if (front == 2) {
                dq.pop_front();
            }
        }
    }

    if (dq.empty()) {
        cout << 0;
    } else {
        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i];
        }
    }
}