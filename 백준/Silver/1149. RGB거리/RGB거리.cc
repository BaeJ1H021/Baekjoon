#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<vector>
#include<cmath>

using namespace std;
int dp[1001][3];
int main()                            
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    dp[i][0] = min(dp[i-1][1],dp[i-1][2])+a;  //i번째 집을 빨강 Paint.
    dp[i][1] = min(dp[i-1][0],dp[i-1][2])+b; //초록.
    dp[i][2] = min(dp[i-1][0],dp[i-1][1])+c; //파랑.
  }
  int ret = min(dp[n][0],min(dp[n][1],dp[n][2]));
  cout << ret;
  return 0;
}
