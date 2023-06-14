#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n,m;
bool visited[10] = {false};
void dfs(int cnt,vector<int> &list)
{
  if(cnt==m)
  {
    for(int i=0;i<list.size();i++)
      cout<< list[i] << " ";
    cout << "\n";
    return;
  }
  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      visited[i] = true;
      list.push_back(i);
      dfs(cnt+1,list);
      list.pop_back();
      visited[i]= false;
    }
  }
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  vector<int> v;
  dfs(0,v);

  return 0;
}
