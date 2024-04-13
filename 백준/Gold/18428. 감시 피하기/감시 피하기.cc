#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
char arr[7][7];
vector<pair<int, int>> teacher;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool flag = false;

void dfs(int y, int x, int cnt) {
  // 기저 사례
  if (cnt == 3) {
    for (int i = 0; i < teacher.size(); i++) {
      int cur_y = teacher[i].first;
      int cur_x = teacher[i].second;
      // 오른쪽 조사
      int rx = cur_x + 1;
      while (rx <= n) {
        // 장애물이나 선생님 만나면 그만
        if (arr[cur_y][rx] == 'O' || arr[cur_y][rx] == 'T')
          break;
        // 학생 만나면 불가능이니까 return
        if (arr[cur_y][rx] == 'S')
          return;
        if (arr[cur_y][rx] == 'X') {
          rx++;
        }
      }
      
      // 왼쪽 조사
      int lx = cur_x - 1;
      while (lx >= 1) {
        // 장애물 만나면 그만
        if (arr[cur_y][lx] == 'O' || arr[cur_y][lx] == 'T')
          break;
        // 학생 만나면 불가능이니까 return
        if (arr[cur_y][lx] == 'S')
          return;
        if (arr[cur_y][lx] == 'X') {
          lx--;
        }
      }
      
      // 위쪽 조사
      int uy = cur_y - 1;
      while (uy >= 1) {
        // 장애물 만나면 그만
        if (arr[uy][cur_x] == 'O' || arr[uy][cur_x] == 'T')
          break;
        // 학생 만나면 불가능이니까 return
        if (arr[uy][cur_x] == 'S')
          return;
        if (arr[uy][cur_x] == 'X') {
          uy--;
        }
      }
      // 아래쪽 조사
      int dy = cur_y + 1;
      while (dy <= n) {
        // 장애물 만나면 그만
        if (arr[dy][cur_x] == 'O' || arr[dy][cur_x] == 'T')
          break;
        // 학생 만나면 불가능이니까 return
        if (arr[dy][cur_x] == 'S')
          return;
        if (arr[dy][cur_x] == 'X') {
          dy++;
        }
      }

    }
    flag = true;
    return;
  }
  // x가 n보다 크면 y올리기.
  if (x > n) {
    y = y + 1;
    x = 1;
  }
  // 3개 뽑기
  for (int i = y; i <= n; i++) {
    // 같은 줄이면 다음 x부터.
    if (i == y) {
      for (int j = x; j <= n; j++) {
        if (arr[i][j] == 'X') {
          arr[i][j] = 'O';
          dfs(i, j + 1, cnt + 1);
          arr[i][j] = 'X';
        }
      }
    } else {
      for (int j = 1; j <= n; j++) {
        if (arr[i][j] == 'X') {
          arr[i][j] = 'O';
          dfs(i, j + 1, cnt + 1);
          arr[i][j] = 'X';
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'T')
        teacher.push_back({i, j});
    }
  }

  dfs(1, 1, 0);

  if (flag)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}