#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n,q;
int arr[70][70]; 
int step[1010];
int len; // 배열 길이
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool visited[70][70];
int max_area = 0;

void rotate(int y, int x, int cut)
{
  int temp[70][70];
  for(int i=1;i<=cut;i++){
    for(int j=1;j<=cut;j++){
      temp[j][cut+1-i] = arr[y+i-1][x+j-1];
    }
  }
  // 반영
  for(int i=1;i<=cut;i++){
    for(int j=1;j<=cut;j++){
      arr[y+i-1][x+j-1] = temp[i][j];
    }
  }
}

void fireStorm(int level)
{
  int cut = pow(2,level);
  for(int i=1;i<=len;i+=cut){
    for(int j=1;j<=len;j+=cut){
       rotate(i,j,cut);
    }
  }
}

void dec_ice()
{
  vector<pair<int,int>> v;
  for(int i=1;i<=len;i++){
    for(int j=1;j<=len;j++){
      // 이미 얼음이 없는 경우 무시
      if(arr[i][j] == 0)
        continue;
      int cnt = 0;
      for(int k=0;k<4;k++){
        int ny = i + dy[k];
        int nx = j + dx[k];
        if(ny > len || ny < 1 || nx > len || nx < 1) continue;
        if(arr[ny][nx] >0)
          cnt++;
      }
      if(cnt <3)
        v.push_back({i,j});
    }
  }
  // 다 끝나고 한 번에 감소
  for(int i=0;i<v.size();i++){
    arr[v[i].first][v[i].second]--;
  }
}

void sum()
{
  int ans = 0;
  for(int i=1;i<=len;i++){
    for(int j=1;j<=len;j++){
      ans += arr[i][j];
    }
  }
  cout << ans << "\n";
}

void bfs(int y, int x)
{
  visited[y][x] = true;
  queue<pair<int,int>> q;
  q.push({y,x});
  int area = 1;
  
  while(!q.empty()){
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if(ny > len || ny < 1 || nx > len || nx < 1) continue;
      if(arr[ny][nx]>0 && !visited[ny][nx]){
        visited[ny][nx] = true;
        q.push({ny,nx});
        area++;
      }
    }
  }
  max_area = max(max_area,area);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> q;
  for(int i=1;i<=pow(2,n);i++){
    for(int j=1;j<=pow(2,n);j++){
      cin >> arr[i][j];
    }
  }

  for(int i=1;i<=q;i++){
    cin >> step[i];
  }

  len = pow(2,n);

  for(int i=1;i<=q;i++){
    fireStorm(step[i]);
    dec_ice();
  }
  
  sum();

  // 큰 덩어리 찾기
  for(int i=1;i<=len;i++){
    for(int j=1;j<=len;j++){
      if(arr[i][j] > 0 && !visited[i][j])
      {
        bfs(i,j);
      }
    }
  }
  cout << max_area;
  
  return 0;
}