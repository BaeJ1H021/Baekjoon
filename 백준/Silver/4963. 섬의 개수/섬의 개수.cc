#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

int n,m;
int arr[51][51] = {0}; 
int dy[8]={0,0,-1,-1,-1,1,1,1};
int dx[8]={-1,1,-1,0,1,-1,0,1};
int cnt_area = 0; //섬이 몇 개 있는지.
void bfs(int y,int x) 
{
  queue<pair<int,int>> q;
  q.push(make_pair(y,x)); //처음위치.
  arr[y][x] = 0; //땅을 바다로만들면서 boolean 대신함.
  while(!q.empty())
  {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop(); 
    for(int i=0;i<8;i++)
    {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if(ny < 1 || ny > n || nx < 1 || nx > m )
        continue;
      if(arr[ny][nx]==1) //영역과 연결된곳.
      {
        arr[ny][nx] = 0;
        q.push(make_pair(ny,nx));
      }
    }
  }
  cnt_area++;
}
void dfs()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(arr[i][j]==1) //땅이면.
        bfs(i,j);
    }
  }
  cout << cnt_area <<"\n";
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  while(1)
  {
    cin >> m >> n ;  //세로,가로.
    if(m==0 && n==0)
      break;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin >> arr[i][j];
      }
    }
    dfs();
    cnt_area = 0; //초기화.
  }
  return 0;
}