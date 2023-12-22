#include<iostream>
#include<algorithm>

using namespace std;

#define INF 2e9

int dp[501][501];
int arr[501];
int sum[501]; //누적합.
int n;

int main()                            
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while(T-->0)
  {
    cin >> n;
    for(int i=1;i<=n;i++)
      cin >> arr[i];
    for(int i=1;i<=n;i++)
    {
      sum[i] = sum[i-1] + arr[i];
      dp[i][i] = 0;
    }
    for(int len=2;len<=n;len++)
    {
      for(int i=1;i<=n-len+1;i++)
      {
        int j = i + len -1;
        dp[i][j] = INF;
        for(int k=i;k<j;k++)
        {
          int cost = dp[i][k]+dp[k+1][j] + sum[j]-sum[i-1];
          dp[i][j] = min(dp[i][j],cost);
        }
      }
    }
    cout << dp[1][n] << "\n"; 
  }
  return 0;
} 

