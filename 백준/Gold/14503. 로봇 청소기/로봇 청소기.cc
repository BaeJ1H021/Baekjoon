#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;

// 장소의 상태 배열.
int arr[52][52];
// 청소하는 칸의 개수.
int cnt = 0;
// 북 동 남 서
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
// 0 -> 3 북 -> 서
// 1 -> 0 동 -> 북
// 2 -> 1 남 -> 동
// 3 -> 2 서 -> 남

void clean(int y, int x, int dir) {
  // 현재 칸이 청소되지 않은 경우.
  if (arr[y][x] == 0) {
    cnt++;
    // 같은 곳 두번 청소 못하게 처리.
    arr[y][x] = 2;
  }
  for (int i = 0; i < 4; i++) {
    int nd = (dir + 3 - i) % 4;
    int ny = y + dy[nd];
    int nx = x + dx[nd];
    if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || arr[ny][nx] == 1)
      continue;
    // 청소되지 않은 빈 칸이라면.
    if (arr[ny][nx] == 0) {
      clean(ny, nx, nd);
    }
  }
  // 주변 4칸중 청소되지 않은 빈 칸이 없는 경우
  // 0 -> 2 1->3 2->0 3->1 후진.
  int back_dir = dir < 2 ? dir + 2 : dir - 2;
  int ny = y + dy[back_dir];
  int nx = x + dx[back_dir];
  // 바라보는 방향 유지한 채로 한 칸 후진 가능하면
  if (ny >= 0 && ny <= n - 1 && nx >= 0 && nx <= m - 1 && arr[ny][nx] == 2) {
    clean(ny, nx, dir);
  } else {
    cout << cnt;
    exit(0);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r, c, d;

  cin >> n >> m;
  cin >> r >> c >> d;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= m - 1; j++) {
      cin >> arr[i][j];
    }
  }
  clean(r, c, d);

  return 0;
}