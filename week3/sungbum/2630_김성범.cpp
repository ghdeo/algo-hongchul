#include <iostream>
using namespace std;

int n;
int map[130][130];
int white, blue;

void go(int y, int x, int width) {
    int init = map[y][x];

    for (int i = y; i < y + width; i++) {
        for (int j = x; j < x + width; j++) {
            if (init != map[i][j]) {
                go(y, x, width / 2);
                go(y, x + width / 2, width / 2);
                go(y + width / 2, x, width / 2);
                go(y + width / 2, x + width / 2, width / 2);
                return;
            }
        }
    }

    if (init == 0) {
        white++;
    } else if (init == 1) {
        blue++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    go(0, 0, n);
    cout << white << "\n";
    cout << blue << "\n";
}