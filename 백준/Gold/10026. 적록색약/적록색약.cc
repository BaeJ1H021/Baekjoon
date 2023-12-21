#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

char arr[101][101];
bool visited[101][101] ={false};
int n;
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int cnt_area = 0;

void bfs(int y,int x,char cha) 
{
  queue<pair<int,int>> q;

  q.push(make_pair(y,x));
  while(!q.empty())
  {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();
    for(int i=0;i<4;i++)
    {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if( ny<1 || ny >n || nx <1 || nx>n )
        continue;
      if( !visited[ny][nx] && arr[ny][nx] == cha ) //방문X, 알파벳 같음.
      {
        visited[ny][nx] = true;
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
    for(int j=1;j<=n;j++)
    {
      if( !visited[i][j] && arr[i][j]=='R')
      {
        bfs(i,j,'R');
      }
      else if(!visited[i][j] && arr[i][j]=='G')
      {
        bfs(i,j,'G');
      }
      else if(!visited[i][j] && arr[i][j]=='B')
      {
        bfs(i,j,'B');
      }
    }
  }
  cout << cnt_area << " ";
  cnt_area = 0; //초기화.
  memset(visited,false,sizeof(visited)); //불리안 초기화.
  for(int i=1;i<=n;i++)     //배열을 적록색맹용으로 바꿈.
  {
    for(int j=1;j<=n;j++)
    {
      if(arr[i][j] == 'B')
        continue;
      else 
        arr[i][j] = 'R'; //그냥 다 빨간색으로 처리.
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if( !visited[i][j] && arr[i][j]=='R')
      {
        bfs(i,j,'R');
      }
      else if(!visited[i][j] && arr[i][j]=='B')
      {
        bfs(i,j,'B');
      }
    }
  }
  cout << cnt_area;
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n; 
  for(int i=1;i<=n;i++)
  {
    string str;
    cin >> str;
    for(int j=1;j<=n;j++)
    {
      arr[i][j] = str[j-1];
    }
  }
  dfs();
  return 0;
}