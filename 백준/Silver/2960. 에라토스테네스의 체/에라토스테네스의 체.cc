#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<cmath>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;
  int cnt = 0;
  cin >> n >> k;
  bool flag[1001] ={false};
  memset(flag,true,sizeof(flag)); //true로 바꾸기.
  flag[0] = flag[1] = false;
  for(int i=2;i<=n;i++)
  {
    if(flag[i])
    {
      for(int j=i;j<=n;j+=i)
      {
        if(flag[j])   //전에 처리한거는 무시하면 됨.
        {
          flag[j] =false;
          cnt++;
          if(k==cnt)
          {
            cout <<j;
            exit(0);
          }
        }
      }
    }
  }
  
  return 0;
}