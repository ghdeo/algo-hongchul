#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 20
using namespace std;

int n, ans;
int map[MAX][MAX];
int arr[MAX][MAX];
int directions[5];

void cpyMap() { // 맵 복사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = map[i][j];
        }
    }
}

void moveLeft() { // 왼쪽으로 모든 블럭 이동
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = j + 1;
                while (k <= n - 1) {
                    if (arr[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                if (check == true) {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                arr[i][j] = arr[i][j] * 2;
                arr[i][j + 1] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = j + 1;
                while (k <= n - 1) {
                    if (arr[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                if (check == true) {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                }
            }
        }
    }
}

void moveRight() { // 오른쪽으로 모든 블록 이동
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0; j--) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = j - 1;
                while (k >= 0) {
                    if (arr[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                if (check == true) {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0; j--) {
            if (arr[i][j] == arr[i][j - 1]) {
                arr[i][j] = arr[i][j] * 2;
                arr[i][j - 1] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0; j--) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = j - 1;
                while (k >= 0) {
                    if (arr[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                if (check == true) {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                }
            }
        }
    }
}

void moveUp() { // 위쪽으로 모든 블록 이동
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = i + 1;
                while (k <= n - 1) {
                    if (arr[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }

                if (check == true) {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == arr[i + 1][j]) {
                arr[i][j] = arr[i][j] * 2;
                arr[i + 1][j] = 0;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = i + 1;
                while (k <= n - 1) {
                    if (arr[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }

                if (check == true) {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                }
            }
        }
    }
}

void moveDown() { // 아래쪽으로 모든 블록 이동
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = i - 1;
                while (k >= 0) {
                    if (arr[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                if (check == true) {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                }
            }
        }
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (arr[i - 1][j] == arr[i][j]) {
                arr[i][j] = arr[i][j] * 2;
                arr[i - 1][j] = 0;
            }
        }
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            bool check = false;
            if (arr[i][j] == 0) {
                int k = i - 1;
                while (k >= 0) {
                    if (arr[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                if (check == true) {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                }
            }
        }
    }

}

int findMax() { // 맵에서 가장 큰 수 찾기
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

void go(int depth) { // dfs
    if (depth == 5) { // 5개의 방향이 모두 기록된 경우 ex) 위 아래 위 위 아래
        cpyMap();

        for (int i = 0; i < 5; i++) {
            int dir = directions[i];
            if (dir == 0) {
                moveRight();
            } else if (dir == 1) {
                moveLeft();
            } else if (dir == 2) {
                moveDown();
            } else if (dir == 3) {
                moveUp();
            }
        }

        ans = max(ans, findMax());
        return;
    }

    for (int i = 0; i < 4; i++) { // 가능한 모든 경우 기록
        directions[depth] = i;
        go(depth + 1);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    go(0);
    cout << ans << endl;

    return 0;
}
