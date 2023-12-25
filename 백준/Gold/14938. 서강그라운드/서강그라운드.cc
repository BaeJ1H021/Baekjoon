#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<vector>
#include<cmath>

using namespace std;

#define INF 1e9

int d[101];
int arr[101]; //놓인 아이템의 수.
vector<pair<int,int>> vec[101];
int v,e,m;

int dijkstra(int start)
{
  int ret = 0;
  fill(d,d+101,INF);
  priority_queue<pair<int,int>> pq;
  pq.push({0,start});   
  d[start] = 0;
  
  while(!pq.empty())
  {
    int dist = -pq.top().first;
    int now = pq.top().second;
    pq.pop();
    
    for(int i=0;i<vec[now].size();i++)
    {
      int next = vec[now][i].first;
      int ndist = vec[now][i].second;
      
      if(dist+ndist<d[next])
      {
        d[next] = dist+ ndist;
        pq.push({-d[next],next});
      }
    }
  }
  for(int i=1;i<=v;i++)
  {
    if(d[i]<=m) //범위 안에 있으면.
      ret += arr[i];
  }
  return ret;
}
int main()                            
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> v >> m >> e;
  for(int i=1;i<=v;i++)
    cin >> arr[i];
  for(int i=1;i<=e;i++)
  {
    int x,y,w; //양방향.
    cin >> x >> y >> w;
    vec[x].push_back({y,w});
    vec[y].push_back({x,w});
  }
  int max_val = -1;
  for(int i=1;i<=v;i++)
    max_val = max(max_val,dijkstra(i));
  cout << max_val;
  return 0;
}