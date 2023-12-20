#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

int n;
int arr[300][300];
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dest_y,dest_x; //목적지.
void bfs(int y,int x) 
{
  queue<pair<int,int>> q;
  q.push(make_pair(y,x));
  while(!q.empty())
  {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    if(cur_y == dest_y && cur_x == dest_x)
      break;
    q.pop();
    for(int i=0;i<8;i++)
    {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if( ny < 0 || ny>n-1 || nx <0 || nx>n-1 ) //범위.
        continue;
      if( arr[ny][nx] == 0 ) //방문X.
      {
        arr[ny][nx] = arr[cur_y][cur_x] + 1;
        q.push(make_pair(ny,nx));
      }
    }
  }
  cout << arr[q.front().first][q.front().second] <<"\n";
  memset(arr,0,sizeof(arr)); //배열 다시 0으로 초기화.
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int T;
  cin >> T; 
  while(T-->0)
  {
    int y,x;
    cin >> n;
    cin >> y >> x;
    cin >> dest_y >> dest_x;
    bfs(y,x);
  }
  return 0;
}