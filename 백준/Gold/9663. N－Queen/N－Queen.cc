#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 줄의 개수
int n;
// 전체 경우의 수
int ans = 0;
// 세로줄 방문 여부
bool visited[16];
// 세로줄 index
int arr[16];

void dfs(int cnt)
{
  // 대각선으로 만나는지 가지치기.
  for(int i=0;i<cnt-1;i++)
  {
    // 대각선상에 있으려면 가로차와 세로차가 같아야함. 
    if(abs(arr[cnt-1]-arr[i]) == cnt-1-i)
      return;
  }
  // 기저사례
  if(cnt==n)  
  {
    ans++;
    return;
  }
  for(int i=0;i<n;i++)
  {  
    // i번째 세로줄에 없다면.
    if(!visited[i])
    {
      visited[i] = true;
      arr[cnt] = i;
      dfs(cnt+1);
      visited[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  dfs(0);
  cout << ans;
  return 0;
}