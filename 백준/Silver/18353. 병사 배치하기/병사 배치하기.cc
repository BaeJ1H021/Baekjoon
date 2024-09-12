#include <iostream>

using namespace std;


int main() {

  int n;
  int arr[2010];
  int dp[2010];
  int max_val = 1;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    dp[i] = 1; // 모두 1로 초기화
  }
  
  for(int i=2;i<=n;i++){
    for(int j=1;j<i;j++){
      if(arr[i]<arr[j]){
        dp[i] = max(dp[i],dp[j]+1);
      }
    }
    // 마지막 병사를 포함하는 것이 정답이 아닐 수도 있으므로 항상 최댓값을 갱신
    max_val = max(max_val,dp[i]);
  }

  cout << n-max_val;

  return 0;
}
