#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<pair<int, int>> q;
int n, m;
int arr[1002][1002];
int visited[1002][1002];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int y, x;

void bfs() {
  for (int i = 0; i < 1002; i++) {
    for (int j = 0; j < 1002; j++) {
      visited[i][j] = -1;
    }
  }

  visited[y][x] = 0;
  q.push({y, x});
  while (!q.empty()) {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if (ny > n || ny < 1 || nx > m || nx < 1)
        continue;
      if (visited[ny][nx] == -1 && arr[ny][nx] == 1) {
        visited[ny][nx] = visited[cur_y][cur_x] + 1;
        q.push({ny, nx});
      }
    }
  }
}

int main() {

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) {
        y = i;
        x = j;
      }
    }
  }

  bfs();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == 0)
        cout << 0 << " ";
      else
        cout << visited[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
