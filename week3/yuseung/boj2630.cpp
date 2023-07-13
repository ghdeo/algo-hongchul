#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int table[150][150];
int bl=0,wh=0;

//true : 이 구간 색종이는 다른 색으로 칠해져있다. 즉! 추가 작업이 필요하다~
bool isColor(int sx, int ex, int sy, int ey){
    
    int cur = table[sx][sy];
    bool fin = false;
    for(int i = sx;i<=ex;i++){
        for(int j= sy;j<=ey;j++){
            if(cur!=table[i][j]){
                fin = true;
                break;
            }
        }
        if(fin)break;
    }
    if(!fin){
        if(cur)bl++;
        else wh++;
    }
    
    return fin;
}


void colorPaper(int sx,int ex,int sy,int ey){
    int cur = table[sx][sy];
    if(sx==ex){
        //시작점과 끝점이 같으면 1칸 -> 무조건 사각형
        if(cur)bl++;
        else wh++;
        return;
    }

    if(!isColor(sx,ex,sy,ey)){
        return ;
    }
    int mx = (sx+ex)/2;
    int my = (sy+ey)/2;

    colorPaper(sx,mx,sy,my);
    colorPaper(mx+1,ex,sy,my);
    colorPaper(sx,mx,my+1,ey);
    colorPaper(mx+1,ex,my+1,ey);
    


    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>table[i][j];
        }
    }
    colorPaper(1,n,1,n);
    cout<<wh<<"\n"<<bl;

    return 0;
}