#include <iostream>

using namespace std;

long long arr[500001];

// 맨 뒤는 반드시 1
// 뒤에서 부터 앞으로 1씩 올리면서 가는 방식
// 물론 값을 내리는건 한없이 내려갈 수 있다, 유지도 가능.
// 1번 예제
// output 2 2 1
// 2번 예제
// output 3 2 1 1
// custom 예제
// input 17 2 23 7 1 5
// output 3 2 3 2 1 1

int main() {
  int n;
  long long sum = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  int prev = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (arr[i] > prev) {
      sum += ++prev;
    } else if (arr[i] == prev) {
      sum += prev;
    } else {
      prev = arr[i];
      sum += prev;
    }
  }

  cout << sum;

  return 0;
}