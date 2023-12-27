#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr[101][101][101];
int n,m,h;
int dy[6]={0,0,-1,1,0,0};
int dx[6]={-1,1,0,0,0,0};
int dz[6]={0,0,0,0,-1,1};
queue<pair<int,pair<int,int>>> q;
bool check() 
{
  for(int i=1;i<=h;i++)
  {
    for(int j=1;j<=n;j++) //세로.
    {
      for(int k=1;k<=m;k++)
      {
        if(arr[i][j][k]==0)
          return false;
      }
    }
  }
  return true;
}
void bfs() 
{
  while(!q.empty())
  {
    int cur_z = q.front().first;
    int cur_y = q.front().second.first;
    int cur_x = q.front().second.second;
    q.pop();
    for(int i=0;i<6;i++)
    {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      int nz = cur_z + dz[i];
      if( ny<1 || ny >n || nx <1 || nx>m || nz <1 || nz > h)
        continue;
      if(arr[nz][ny][nx] == 0 )
      {
        arr[nz][ny][nx] = arr[cur_z][cur_y][cur_x] + 1;
        q.push(make_pair(nz,make_pair(ny,nx)));
      }
    }
  }
  if(check())
  {
    int max_val = 0;
    for(int i=1;i<=h;i++)
    {
      for(int j=1;j<=n;j++)
      {
        for(int k=1;k<=m;k++)
        {
          if(max_val < arr[i][j][k]-1)
            max_val = arr[i][j][k]-1;
        }    
      }
    }
    cout <<max_val;
  }
  else
    cout << -1;
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> n >> h; //가로,세로,높이.
  for(int i=1;i<=h;i++) //높이
  {
    for(int j=1;j<=n;j++)   //세로
    {
      for(int k=1;k<=m;k++) //가로.
      {
        cin >> arr[i][j][k];
        if(arr[i][j][k]==1)
          q.push(make_pair(i,make_pair(j,k)));
      }
    }
  }
  bfs();
  return 0;
}