#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

char ans[4]={'2','0','2','3'};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll N;cin>>N;
    if(N<2023){
        cout<<0;return 0;
    }
    ll cnt =0;

    for(ll i = 2023;i<=N;i++){
        string tmp = to_string(i);
        ll len = tmp.length();
        int p = 0;
        for(int j=0;j<len;j++){
            if(tmp[j]==ans[p]){
                p++;
            }
            if(p==4){
                p=0;cnt++;break;
            }
        }
    }
    cout<<cnt;


    return 0;
}