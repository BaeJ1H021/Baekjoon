#include <iostream>
using namespace std;

int main() { 

  int n;
  cin >> n;

  int max_dp[3];
  int min_dp[3];
  int input[3];
  
  int num;
  // 첫번째 줄 입력.
  cin >> input[0] >> input[1] >> input[2];
  max_dp[0] = min_dp[0] = input[0];
  max_dp[1] = min_dp[1] = input[1];
  max_dp[2] = min_dp[2] = input[2];
  // 메모리 제한 문제로 슬라이딩 윈도우 기법 사용.
  for(int i=2;i<=n;i++)
  {
    cin >> input[0] >> input[1] >> input[2];
    // 전에 층까지 누적 값을 저장해둘 배열.
    int temp[3];
    temp[0] = max_dp[0]; 
    temp[1] = max_dp[1];
    temp[2] = max_dp[2];
    max_dp[0] = max(temp[0],temp[1])+input[0];
    max_dp[1] = max(max(temp[0],temp[1]),temp[2])+input[1];
    max_dp[2] = max(temp[1],temp[2])+input[2];
    temp[0] = min_dp[0]; 
    temp[1] = min_dp[1];
    temp[2] = min_dp[2];
    min_dp[0] = min(temp[0],temp[1])+input[0];
    min_dp[1] = min(min(temp[0],temp[1]),temp[2])+input[1];
    min_dp[2] = min(temp[1],temp[2])+input[2];
  }
  cout << max(max(max_dp[0],max_dp[1]),max_dp[2]) << " " << min(min(min_dp[0],min_dp[1]),min_dp[2]);
  return 0; 
}