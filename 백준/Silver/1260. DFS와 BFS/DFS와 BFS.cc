#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>

using namespace std;


int n,m,v;
vector<int> vec[1001];
bool visited[1001] ={false};
void dfs(int num)  
{
  cout << num << " ";
  visited[num] = true;
  for(int i=0;i<vec[num].size();i++)
  {
    int x = vec[num][i]; //num에 i번쨰 연결된 정점. 
    if(!visited[x])
      dfs(x);
  }
}
void bfs(int num)
{
  queue<int> q;
  q.push(num);
  visited[num] = true;
  while(!q.empty())
  {
    int cur = q.front();
    cout << cur << " ";
    q.pop();
    for(int i=0;i<vec[cur].size();i++)
    {
      int x = vec[cur][i]; //cur에 i번째 연결된 정점.
      if(!visited[x])
      {
        visited[x] = true;
        q.push(x);
      }
    }
  }
}
int main()                            
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> v;
  for(int i=1;i<=m;i++)
  {
    int x,y;
    cin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
  {
    sort(vec[i].begin(),vec[i].end());
  }
  dfs(v);
  memset(visited,false,sizeof(visited));
  cout << "\n";
  bfs(v);
  
  return 0;
}