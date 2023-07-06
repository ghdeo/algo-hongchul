#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

#define endl "\n"
#define ll long long

#define M 20
int ans;
int n;

deque<int> dq[M];
int board[M][M];

void reset()
{
    for (int i = 0; i < n ; i ++)
        for (int j = 0 ; j < n; j++)
            dq[j].push_back(board[i][j]);
}
    
void left()
{
    for (int i = 0 ; i < n; i ++)
    {
        deque<int> t_dq; 
        while (!dq[i].empty())
        {
            if (dq[i].front() == 0)
            {
                dq[i].pop_front();
                continue;
            }

            int t = dq[i].front();
            dq[i].pop_front();
            if (!dq[i].empty() && t == dq[i].front())
            {
                t_dq.push_back(t << 1);
                dq[i].pop_front();
            }
            else
            {
                t_dq.push_back(t);
            }
        }
        while (!t_dq.empty())
        {
            dq[i].push_back(t_dq.front());
            t_dq.pop_front();
        }
        while (dq[i].size() < n)
        {
            dq[i].push_back(0);
        }
    }
}

void right()
{
    for (int i = 0 ; i < n; i ++)
    {
        deque<int> t_dq; 
        while (!dq[i].empty())
        {
            if (dq[i].back() == 0)
            {
                dq[i].pop_back();
                continue;
            }

            int t = dq[i].back();
            dq[i].pop_back();
            if (!dq[i].empty() && t == dq[i].back())
            {
                t_dq.push_front(t << 1);
                dq[i].pop_back();
            }
            else
            {
                t_dq.push_front(t);
            }
        }
        while (!t_dq.empty())
        {
            dq[i].push_front(t_dq.back());
            t_dq.pop_back();
        }
        while (dq[i].size() < n)
        {
            dq[i].push_front(0);
        }
    }
}

void up()
{
    for (int i = 0 ; i < n; i ++)
    {
        deque<int> t_dq;
        for (int j = 0; j < n; j ++)
        {
            int t = dq[j].front();
            
            dq[j].pop_front();
            if (!t_dq.empty() && t == t_dq.front())
            {
                t_dq.pop_front();
                t_dq.push_front(t << 1);
                t_dq.push_front(0);
            }
            else if (t)
                t_dq.push_front(t);
        }
        for (int j = 0; j < n; j ++)
        {
            if (!t_dq.empty())
            {
                while (!t_dq.empty() && t_dq.back() == 0)
                {
                    t_dq.pop_back();
                }
                if (!t_dq.empty())
                {
                    dq[j].push_back(t_dq.back());
                    t_dq.pop_back();
                }
            }
            else
                dq[j].push_back(0);
        }
    }
}


void down()
{
    for (int i = 0 ; i < n; i ++)
    {
        deque<int> t_dq;
        for (int j = n - 1; j > -1; j --)
        {
            int t = dq[j].front();
            dq[j].pop_front();
            if (!t_dq.empty() && t == t_dq.front())
            {
                t_dq.pop_front();
                t_dq.push_front(t << 1);
                t_dq.push_front(0);
            }
            else if (t)
                t_dq.push_front(t);
        }
        for (int j = n - 1; j > -1; j --)
        {
            if (!t_dq.empty())
            {
                while (!t_dq.empty() && t_dq.back() == 0)
                {
                    t_dq.pop_back();
                }
                if (!t_dq.empty())
                {
                    dq[j].push_back(t_dq.back());
                    t_dq.pop_back();
                }
            }
            else
                dq[j].push_back(0);
        }
    }
}

void findmax ()
{
    for (int i = 0 ; i < n; i ++)
    {
        while(!dq[i].empty())
        {
            ans = max(ans, dq[i % n].front());
            dq[i % n].pop_front();
        }
    }
}

void shift(int t)
{
  switch (t) {
    case 0:
    left();
    break;
    case 1:
    right();
    break;
    case 2:
    up();
    break;
    case 3:
    down();
    break;
  }
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int tmp;
    cin >> n;
    for (int i = 0 ; i < n * n; i ++)
    {
        cin >> tmp;
        board[i/n][i%n] = tmp;
    }
    for (int i = 0; i < 4; i++)
    {
        reset();
        for (int j = 0; j < 4; j++)
        {
            for (int k  = 0 ; k < 4; k++)
            {
                for (int y = 0 ; y < 4; y++)
                {
                    for (int x = 0 ;x < 4; x++)
                    {
                        shift(i);
                        shift(j);
                        shift(k);
                        shift(x);
                        shift(y);
                    }
                }
            }
        }
        findmax();
    }
    cout<< ans;


    return 0;
}
