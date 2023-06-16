#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int result =0;
bool visited[15]={false};
void dfs(int cnt,vector<int> &x)
{
  //검사.  x[i],y[i]는 인덱스임.
  for(int i=0;i<cnt-1;i++)
  {
    //대각선 계산이 더 쉬운게 있다. 아니 이걸 내가 어떻게알아;
    if( cnt-1-i == abs(x[cnt-1]-x[i]))  
      return;
  }
  if(cnt ==n) //다 놓았으면.
  {
    result++;
    return;
  }
  for(int j=0;j<n;j++)
  {
    if(!visited[j]) //j번째 세로줄을 방문했는지. 
    {
      visited[j] = true;
      x.push_back(j);
      dfs(cnt+1,x);
      visited[j] = false;
      x.pop_back();
    }
  }
}

int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin>> n;
  vector<int> b;
  dfs(0,b);
  cout << result;
  return 0;
}