#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory.h>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  // 알파벳 개수 A~Z
  int arr[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    arr[s[i] - 'A']++;
  }
  // 알파벳의 개수가 홀수이면 카운트.
  int cnt = 0;
  // 홀수일 때 중간에 출력할 알파벳 저장.
  char c;
  for (int i = 0; i < 26; i++) {
    if (arr[i] % 2 == 1) {
      cnt++;
      c = char('A' + i);
    }
  }
  // 홀수가 1개보다 많으면 팰린드롬 불가능.
  if (cnt > 1) {
    cout << "I'm Sorry Hansoo";
  } else {
    // 정답 저장할 문자열.
    string ans = "";
    for (int i = 0; i < 26; i++) {
      while (arr[i] >= 2) {
        ans += char('A' + i);
        arr[i] -= 2;
      }
    }
    cout << ans;
    reverse(ans.begin(), ans.end());
    // 홀수인 알파벳이 하나있다면 중간에 출력.
    if(cnt==1)
      cout << c;
    cout << ans;
  }
  return 0;
}