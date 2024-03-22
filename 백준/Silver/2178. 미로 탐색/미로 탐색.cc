#include <algorithm>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n, m;
char arr[105][105];
int visited[105][105];

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

void bfs() {
  queue<pair<int, int>> q;
  q.push({1, 1});
  visited[1][1] = 0;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 1 || ny > n || nx < 1 || nx > m)
        continue;
      if(arr[ny][nx] == '1' && visited[ny][nx] == -1)
      {
        visited[ny][nx] = visited[y][x] + 1;
        q.push({ny,nx});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  memset(visited, -1, sizeof(visited));
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      arr[i][j] = s[j-1];
    }
  }
  bfs();
  cout << visited[n][m]+1;
  return 0;
}