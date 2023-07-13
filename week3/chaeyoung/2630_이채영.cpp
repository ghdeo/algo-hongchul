#include <iostream>
using namespace std;

int n;
int arr[129][129];

int b, w;

void dfs(int len, int x, int y)
{
    int countB = 0;
    int countW = 0;

    for (int i = x; i < x + len; i++)
    {
        for (int j = y; j < y + len; j++)
        {
            if (arr[i][j] == 1)
                countB++;
            else
                countW++;
        }
    }

    if (countB == len * len)
    {
        b++;
        return;
    }

    if (countW == len * len)
    {
        w++;
        return;
    }

    dfs(len/2, x, y);
    dfs(len / 2, x + len / 2, y);
    dfs(len / 2, x + len / 2, y + len / 2);
    dfs(len / 2, x, y + len / 2);
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(n, 0, 0);

    cout << w << "\n" << b;

    return 0;
}