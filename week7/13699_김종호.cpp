#include<iostream>

using namespace std;

long long ary[35+1];


int main(void)
{
  ary[0]=1;

  int n;
  cin >>n;

  for(int i=1;i<=n;i++)
   {
     for(int j=0;j<i;j++)
     {
       ary[i]+=ary[j]*ary[i-j-1];
     }
   }
  cout<<ary[n];

  return 0;

}
