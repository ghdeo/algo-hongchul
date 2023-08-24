#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> location(4);

void solve(char tmp){
    switch(tmp){
        case 'A':
            swap(location[0],location[1]);
            break;
        case 'B':
            swap(location[0],location[2]);
            break;
        case 'C':
            swap(location[0],location[3]);            
            break;
        case 'D':
            swap(location[1],location[2]);
            break;
        case 'E':
            swap(location[1],location[3]);
            break;
        case 'F':
            swap(location[2],location[3]);
            break;
        default:
            break;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(location.begin(),location.end(),-1);//-1이면 공이 없음
    location[0]=1;location[3]=2;//1이면 작은공 2면 큰공이 i에 있다.

    string s;cin>>s;
    int size = s.length();

    for(int i=0;i<size;i++){
        solve(s[i]);
    }

    int sm,bg;
    for(int i=0;i<4;i++){
        if(location[i]==1){
            sm=i+1;
        }
        else if(location[i]==2){
            bg=i+1;
        }
    }

    cout<<sm<<"\n"<<bg;

    return 0;
}