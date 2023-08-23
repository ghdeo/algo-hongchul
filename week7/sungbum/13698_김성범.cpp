#include <iostream>
#include <string>
using namespace std;

char cup[4];

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cup[0] = 's';
    cup[1] = 'n';
    cup[2] = 'n';
    cup[3] = 'b';

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            swap(cup[0], cup[1]);
        } else if (s[i] == 'B') {
            swap(cup[0], cup[2]);
        } else if (s[i] == 'C') {
            swap(cup[0], cup[3]);
        } else if (s[i] == 'D') {
            swap(cup[1], cup[2]);
        } else if (s[i] == 'E') {
            swap(cup[1], cup[3]);
        } else if (s[i] == 'F') {
            swap(cup[2], cup[3]);
        }
    }
    int small, big;
    for (int i = 0; i < 4; i++) {
        if (cup[i] == 's') {
            small = i + 1;
        }
        if (cup[i] == 'b') {
            big = i + 1;
        }
    }

    cout << small << "\n" << big;
}