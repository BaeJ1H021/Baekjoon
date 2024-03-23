#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<memory.h>

using namespace std;

int n,m;
int arr[501][501];
bool visited[501][501] ={false};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int area_cnt=0;
int max_area = 0;
void bfs(int y,int x)
{
  queue<pair<int,int>> q;
  q.push(make_pair(y,x)); //시작점 넣고.
  visited[y][x] = true;
  int area = 1; //그림 넓이.
  while(!q.empty())
  {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();
    for(int i=0;i<4;i++)
    {
      int ny = cur_y +dy[i];
      int nx = cur_x +dx[i];
      if(ny<1 || nx<1 || ny>n || nx>m) //범위.
        continue;
      if(!visited[ny][nx] && arr[ny][nx]==1)
      {
        visited[ny][nx] = true;
        q.push(make_pair(ny,nx));
        area++;
      }
    }
  }
  area_cnt++; //그림 개수 추가.
  max_area = max(max_area,area);
}
void dfs()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(!visited[i][j] && arr[i][j] == 1)
        bfs(i,j);
    }
  }
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin >> arr[i][j];
    }
  }
  dfs();
  cout << area_cnt << "\n";
  cout << max_area;
  return 0;
}