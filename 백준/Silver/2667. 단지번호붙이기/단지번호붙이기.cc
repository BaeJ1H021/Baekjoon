#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr[26][26];
bool visited[26][26] = {false};
int n;
vector<int> v;
int hometown = 0 ; //단지수.
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
void bfs(int y, int x) 
{
  queue<pair<int,int>> q;
  
  int cnt=1; //집의 개수.
  visited[y][x] = true; //시작점 방문.
  q.push(make_pair(y,x)); //시작점 넣기.
  while(!q.empty())
  {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();
    for(int i=0;i<4;i++)
    {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if( ny<1 || ny >n || nx <1 || nx>n)
        continue;
      if(arr[ny][nx] == 1 && !visited[ny][nx])
      {
        cnt++;
        visited[ny][nx] = true;
        q.push(make_pair(ny,nx));
      }
    }
  }
  v.push_back(cnt);
}
void dfs()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(arr[i][j] == 1 && !visited[i][j])
      {
        bfs(i,j);
        hometown++;
      }
    }
  }
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    string s;
    cin >> s;
    for(int j=1;j<=n;j++)
      arr[i][j] = s[j-1]-'0';
  }
  dfs();
  sort(v.begin(),v.end());
  cout << hometown << "\n";
  for(int i=0;i<v.size();i++)
    cout << v[i] << "\n";
    
  return 0;
}