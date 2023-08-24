#include <iostream>
#include <string>
using namespace std;
int main() {
    string word;
    int cup[4] = { 1,0,0,2 },a,b;
    cin >> word;
    for (int i = 0; i < word.size(); i++)
    {
        switch ((char)word[i])
        {
            case 'A':
                swap(cup[0], cup[1]);
                break;
            case 'B':
                swap(cup[0], cup[2]);
                break;
            case 'C':
                swap(cup[0], cup[3]);
                break;
            case 'D':
                swap(cup[1], cup[2]);
                break;
            case 'E':
                swap(cup[1], cup[3]);
                break;
            case 'F':
                swap(cup[2], cup[3]);
                break;
        }

    }
    for (int i = 0; i < 4; i++)
    {
        if (cup[i] == 1)
            a= i + 1;
        else if (cup[i] == 2)
            b = i + 1;
    }
    cout << a << '\n' << b;
}