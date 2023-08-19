#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>

#define endl "\n"
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >>N;
    int ans = 0;
    for (int i = 2023; i <= N; i++)
    {
        string s = to_string(i);
        int a = s.find('2',0);
        int b = s.find('0',a + 1);
        int c = s.find('2',b + 1);
        int d = s.find('3',c + 1);
        if (b > 0 && c > 0 && d > 0)
            ans++;
    }
    cout <<ans;
    return 0;
}