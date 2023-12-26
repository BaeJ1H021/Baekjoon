#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<memory.h>
#include<vector>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int n,k;
pair<int,int> jew[300001];
int bag[300001];
priority_queue<int> pq;

int main()                             
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  // 가방 무게 1 3 5 7 이라고 하면 , 7이 들수 있는게  1무게짜리 제일 비싼거면.
  // 그건 7이 들 게 아니라 1이 들어야 함.
  // 따라서 가방,보석 둘 다 오름차순 정렬하자.

  cin >> n >> k;
  for(int i=1;i<=n;i++)
    cin >> jew[i].first >> jew[i].second; //무게, 돈.
  for(int i=1;i<=k;i++)
    cin >> bag[i];
  
  sort(jew+1,jew+n+1);
  sort(bag+1,bag+k+1);

  //모든 가방에 대해서 넣을 수 있는 보석을 매 번 계산하면
  //시간복잡도가 O(n^2)이 나와서 시간초과가 뜬다.
  //용량이 더 작은 가방에 들어간 보석은 용량이 더 큰 가방에도 들어가므로
  //이전 가방에 담았던걸 그대로 우선순위 큐에 넣어놓으면 O(n)으로 풀 수 있다.
  long long sum = 0;
  for(int i=1,j=1;i<=k;i++) //i는 가방,j는 보석.
  {
    while( j<=n && jew[j].first<=bag[i]) //가방에 넣을 수 있으면.
    {
      pq.push(jew[j++].second);
    }
    if(!pq.empty())
    {
      sum += pq.top();
      pq.pop();
    }
  }
  cout << sum;
  return 0;
} 