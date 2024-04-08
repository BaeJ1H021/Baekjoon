#include <algorithm>
#include <iostream>

using namespace std;

int r, c, t;
int arr[53][53];
bool isFirst = true;
pair<int, int> up_air;
pair<int, int> down_air;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void diffuse() {
  int temp[53][53] = {
      0,
  };
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      // 미세먼지가 있으면
      if (arr[i][j] > 0) {
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
          int ny = i + dy[k];
          int nx = j + dx[k];
          // 벽 나가는거 체킹
          if (ny < 1 || ny > r || nx < 1 || nx > c)
            continue;
          // 미세먼지 가동기가 없으면
          if (arr[ny][nx] != -1) {
            temp[ny][nx] += arr[i][j] / 5;
            cnt += arr[i][j] / 5;
          }
        }
        arr[i][j] -= cnt; // 맨 마지막에 한꺼번에 감소.
      }
    }
  }
  // 확산 끝나면 저장해 놓은 temp를 arr에 반영
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      arr[i][j] += temp[i][j];
    }
  }
}

void up_wind() {
  // 거꾸로 순환하면 바로 대입 가능
  int cur_y = up_air.first - 1;
  int cur_x = up_air.second;
  while (cur_y >= 2) {
    arr[cur_y][cur_x] = arr[cur_y - 1][cur_x];
    cur_y--;
  }
  while (cur_x + 1 <= c) {
    arr[cur_y][cur_x] = arr[cur_y][cur_x + 1];
    cur_x++;
  }
  while (cur_y + 1 <= up_air.first) {
    arr[cur_y][cur_x] = arr[cur_y + 1][cur_x];
    cur_y++;
  }
  while (cur_x >= up_air.second + 2) {
    arr[cur_y][cur_x] = arr[cur_y][cur_x - 1];
    cur_x--;
  }
  arr[cur_y][cur_x] = 0;
}

void down_wind() {
  // 거꾸로 순환하면 바로 대입 가능
  int cur_y = down_air.first + 1;
  int cur_x = down_air.second;
  while (cur_y + 1 <= r) {
    arr[cur_y][cur_x] = arr[cur_y + 1][cur_x];
    cur_y++;
  }
  while (cur_x + 1 <= c) {
    arr[cur_y][cur_x] = arr[cur_y][cur_x + 1];
    cur_x++;
  }
  while (cur_y - 1 >= down_air.first) {
    arr[cur_y][cur_x] = arr[cur_y - 1][cur_x];
    cur_y--;
  }
  while (cur_x >= down_air.second + 2) {
    arr[cur_y][cur_x] = arr[cur_y][cur_x - 1];
    cur_x--;
  }
  arr[cur_y][cur_x] = 0;
}

void sum() {
  int cnt = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (arr[i][j] > 0)
        cnt += arr[i][j];
    }
  }
  cout << cnt;
}

void simulate() {
  diffuse();
  up_wind();
  down_wind();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> c >> t;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == -1 && isFirst) {
        up_air = {i, j};
        down_air = {i + 1, j};
        isFirst = false;
      }
    }
  }

  while (t-- > 0) {
    simulate();
  }

  sum();

  return 0;
}