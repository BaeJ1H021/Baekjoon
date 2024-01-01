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

int n;
int from[200001];
int to[200001];
vector<pair<int,int>> order;
priority_queue<int,vector<int>,greater<int>> pq;

int main()                             
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    cin >> from[i] >> to[i];
    order.push_back({from[i],to[i]});
  }
  sort(order.begin(),order.end());

  pq.push(order[0].second); //제일 먼저 시작한거.
  for(int i=1;i<n;i++)
  {
    int meet_end = order[i].second;
    int meet_start = order[i].first;
    if(pq.top()>meet_start) //제일 먼저 시작할 수 있는거.
      pq.push(meet_end);
    else
    {
      pq.pop();
      pq.push(meet_end);
    }
  }  
  cout << pq.size();
  return 0;
} 
