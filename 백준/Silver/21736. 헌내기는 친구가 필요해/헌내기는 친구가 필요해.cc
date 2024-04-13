#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
char arr[605][605];
bool visited[605][605];
int cnt = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
pair<int,int> start;

void dfs(int y, int x)
{
  visited[y][x] = true;
  if(arr[y][x]=='P')
    cnt++;
  for(int i=0;i<4;i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny <1 || ny > n || nx < 1 || nx>m || arr[ny][nx] == 'X')
      continue;
    if(!visited[ny][nx]){
      dfs(ny,nx);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(int i=1;i<=n;i++){
    string s;
    cin >> s;
    for(int j=1;j<=m;j++){
      arr[i][j] = s[j-1];
      if(arr[i][j] == 'I')
        start= {i,j};
    }
  }

  dfs(start.first,start.second);
  if(cnt == 0)
    cout << "TT";
  else
    cout << cnt;
  return 0;
}