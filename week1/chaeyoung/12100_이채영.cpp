#include <iostream>
#include <cstring>

#define MAX 20
using namespace std;

int N, Answer;
int MAP[MAX][MAX];
int MAP_COPIED[MAX][MAX];
int Select[5];
bool Visited[MAX][MAX];

int findMax() {
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (MAP_COPIED[i][j] > max) {
                max = MAP_COPIED[i][j];
            }
        }
    }
    return max;
}

void moveDown() {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < N; j++) {
            bool check = false;
            //왼쪽 아래부터 칸에 값이 존재하는지 확인(0인지 아닌지)
            //0이라면 위쪽으로 값이 존재하는지 확인
            if (MAP_COPIED[i][j] == 0) {
                int k = i - 1;
                while (k >= 0) {
                    //값이 존재하는 부분까지 가서 도달하면 존재한다고 바꾼뒤
                    if (MAP_COPIED[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                //값이 존재하는 부분의 값을 아래쪽으로 땡기고 옮겨진 위치는 0으로 바꾸기
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[k][j];
                    MAP_COPIED[k][j] = 0;
                }
            }
        }
    }

    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < N; j++) {   //아래에서부터 위쪽으로 두 칸의 값이 같은 경우
            if  (MAP_COPIED[i][j] == MAP_COPIED[i - 1][j]) {
                //아래부분으로 값을 몰아서 더하고(2배) 위쪽의 값은 0으로 바꾼다
                MAP_COPIED[i][j] = MAP_COPIED[i][j] * 2;
                MAP_COPIED[i - 1][j] = 0;
            }
        }
    }
    //가장 처음에 오른쪽으로 몰았던 거처럼 다시 한 번 오른쪽으로 값을 몰아준다.
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < N; j++) {
            bool check = false;
            //왼쪽 아래부터 칸에 값이 존재하는지 확인(0인지 아닌지)
            //0이라면 위쪽으로 값이 존재하는지 확인
            if (MAP_COPIED[i][j] == 0) {
                int k = i - 1;
                while (k >= 0) {
                    //값이 존재하는 부분까지 가서 도달하면 존재한다고 바꾼뒤
                    if (MAP_COPIED[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                //값이 존재하는 부분의 값을 아래쪽으로 땡기고 옮겨진 위치는 0으로 바꾸기
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[k][j];
                    MAP_COPIED[k][j] = 0;
                }
            }
        }
    }
}


void moveUp() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            bool check = false;
            //왼쪽 위부터 칸에 값이 존재하는지 확인(0인지 아닌지)
            //0이라면 아래쪽으로 값이 존재하는지 확인
            if (MAP_COPIED[i][j] == 0) {
                int k = i + 1;
                while (k <= N - 1) {
                    //값이 존재하는 부분까지 가서 도달하면 존재한다고 바꾼뒤
                    if (MAP_COPIED[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                //값이 존재하는 부분의 값을 위쪽으로 땡기고 옮겨진 위치는 0으로 바꾸기
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[k][j];
                    MAP_COPIED[k][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {   //위에서부터 아래쪽으로 두 칸의 값이 같은 경우
            if (MAP_COPIED[i][j] == MAP_COPIED[i + 1][j]) {
            //위쪽부분으로 값을 몰아서 더하고(2배) 아래쪽의 값은 0으로 바꾼다
                MAP_COPIED[i][j] = MAP_COPIED[i][j] * 2;
                MAP_COPIED[i + 1][j] = 0;
            }
        }
    }
    //가장 처음에 오른쪽으로 몰았던 거처럼 다시 한 번 오른쪽으로 값을 몰아준다.
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            bool check = false;
            //왼쪽 위부터 칸에 값이 존재하는지 확인(0인지 아닌지)
            //0이라면 아래쪽으로 값이 존재하는지 확인
            if (MAP_COPIED[i][j] == 0) {
                int k = i + 1;
                while (k <= N - 1) {
                    //값이 존재하는 부분까지 가서 도달하면 존재한다고 바꾼뒤
                    if (MAP_COPIED[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                //값이 존재하는 부분의 값을 위쪽으로 땡기고 옮겨진 위치는 0으로 바꾸기
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[k][j];
                    MAP_COPIED[k][j] = 0;
                }
            }
        }
    }
}

void moveLeft() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            bool check = false;
            //왼쪽에서부터 칸에 값이 존재하는지 확인(0인지 아닌지)
            //0이라면 오른쪽으로 값이 존재하는지 확인
            if (MAP_COPIED[i][j] == 0) {
            int k = j + 1;
            while (k <= N - 1) {
                //값이 존재하는 부분까지 가서 도달하면 존재한다고 바꾼뒤
                if (MAP_COPIED[i][k] != 0) {
                    check = true;
                    break;
                }
                k++;
            }
            //값이 존재하는 부분의 값을 왼쪽으로 땡기고 옮겨진 위치는 0으로 바꾸기
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[i][k];
                    MAP_COPIED[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {   //왼쪽에서부터 오른쪽으로 두 칸의 값이 같은 경우
            if (MAP_COPIED[i][j] == MAP_COPIED[i][j + 1]) {
            //오른쪽 끝부분으로 값을 몰아서 더하고(2배) 왼쪽의 값은 0으로 바꾼다
                MAP_COPIED[i][j] = MAP_COPIED[i][j] * 2;
                MAP_COPIED[i][j + 1] = 0;
            }
        }
    }
    //가장 처음에 오른쪽으로 몰았던 거처럼 다시 한 번 오른쪽으로 값을 몰아준다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            bool check = false;
            //왼쪽에서부터 칸에 값이 존재하는지 확인(0인지 아닌지)
            //0이라면 오른쪽으로 값이 존재하는지 확인
            if (MAP_COPIED[i][j] == 0) {
                int k = j + 1;
                while (k <= N - 1) {
                    //값이 존재하는 부분까지 가서 도달하면 존재한다고 바꾼뒤
                    if (MAP_COPIED[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                //값이 존재하는 부분의 값을 왼쪽으로 땡기고 옮겨진 위치는 0으로 바꾸기
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[i][k];
                    MAP_COPIED[i][k] = 0;
                }
            }
        }
    }
}

void moveRight()
{
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > 0; j--) {
            bool check = false;
            //오른쪽에서부터 칸에 값이 존재하는지 확인(0인지 아닌지)
            //0이라면 왼쪽으로 값이 존재하는지 확인
            if (MAP_COPIED[i][j] == 0) {
                int k = j - 1;
                while (k >= 0) {
                    //값이 존재하는 부분까지 가서 도달하면 존재한다고 바꾼뒤
                    if (MAP_COPIED[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                //값이 존재하는 부분의 값을 오른쪽으로 땡기고 옮긴 위치는 0으로 바꾸기
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[i][k];
                    MAP_COPIED[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > 0; j--) {   //오른쪽에서부터 왼쪽으로 두 칸의 값이 같은 경우
            if (MAP_COPIED[i][j] == MAP_COPIED[i][j - 1]) {
            //오른쪽 끝부분으로 값을 몰아서 더하고(2배) 왼쪽의 값은 0으로 바꾼다
                MAP_COPIED[i][j] = MAP_COPIED[i][j] * 2;
                MAP_COPIED[i][j - 1] = 0;
            }
        }
    }
    //가장 처음에 오른쪽으로 몰았던 거처럼 다시 한 번 오른쪽으로 값을 몰아준다.
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > 0; j--) {
            bool check = false;
            if (MAP_COPIED[i][j] == 0) {
                int k = j - 1;
                while (k >= 0) {
                    if (MAP_COPIED[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                if (check == true) {
                    MAP_COPIED[i][j] = MAP_COPIED[i][k];
                    MAP_COPIED[i][k] = 0;
                }
            }
        }
    }
}

void copyMap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            MAP_COPIED[i][j] = MAP[i][j];
        }
    }
}

void selectDirection(int index, int count) {
    //5회동안 진행
    if (count == 5) {
        copyMap();
        for (int i = 0; i < 5; i++) {
            int direction = Select[i];
            if (direction == 0) moveRight();
            else if (direction == 1) moveLeft();
            else if (direction == 2) moveDown();
            else if (direction == 3) moveUp();
        }
        Answer = (Answer > findMax()) ? Answer : findMax();
        
        return;
    }
    for (int i = 0; i < 4; i++) {
        Select[count] = i;
        selectDirection(i, count + 1);
    }
}

void solution() {
    selectDirection(0, 0);
    cout << Answer << "\n";
}

int main() {
    //백준을 위한 시간초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //값 입력받기
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
    solution();
}