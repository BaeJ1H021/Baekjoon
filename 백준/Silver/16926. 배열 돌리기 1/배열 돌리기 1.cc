#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n,m,r;

int arr[310][310];
int temp[310][310];

int cnt = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> r;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> arr[i][j];
    }
  }

  while(cnt<r){
    for(int i=1;i<=min(m,n)/2;i++){
      // 상, 하 회전
      for(int j=i;j<=m-i;j++){ 
        if(cnt % 2 == 0){
          // 윗 줄
          temp[i][j] = arr[i][j+1];
          // 아랫 줄
          temp[n+1-i][j+1] = arr[n+1-i][j]; 
        }
        else{
          // 윗 줄
          arr[i][j] = temp[i][j+1];
          // 아랫 줄
          arr[n+1-i][j+1] = temp[n+1-i][j]; 
        }
      }
      // 좌, 우 회전
      for(int j=i;j<=n-i;j++){
        if(cnt % 2 == 0){
          // 왼쪽 줄
          temp[j+1][i] = arr[j][i];
          // 오른쪽 줄
          temp[j][m+1-i] = arr[j+1][m+1-i];
        }
        else{
          // 왼쪽 줄
          arr[j+1][i] = temp[j][i];
          // 오른쪽 줄
          arr[j][m+1-i] = temp[j+1][m+1-i];
        }
      }
    }
    cnt++;
  }

  if(r % 2 == 0){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cout << arr[i][j] << " ";
      }
      cout << "\n";
    }
  }
  else{
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cout << temp[i][j] << " ";
      }
      cout << "\n";
    }
  }
  
  return 0;
}