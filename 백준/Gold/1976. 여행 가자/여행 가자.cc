#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<vector>
#include<iomanip>
#include<cmath>

using namespace std;

#define INF 1e9

int parent[201];
int Find(int x) //경로 압축.
{
  if(parent[x]==x)
    return x;
  return parent[x] = Find(parent[x]);
}
void Union(int x,int y) //부모가 작은쪽으로 합침.
{
  x = Find(x);
  y = Find(y);
  if(x!=y)
  {
    if(x<y)
      parent[y] = x;
    else
      parent[x] = y;
  }
}
int main()                            
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  for(int i=0;i<=n;i++)
    parent[i] = i;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      int num;
      cin >> num;
      if(num==1) //합집합.
        Union(i,j);
    }
  }
  int root;
  bool flag = true;
  for(int i=1;i<=m;i++)
  {
    int num;
    cin >> num;
    if(i==1)
      root = Find(num);
    else
    {
      if(Find(num)!=root)
        flag = false; 
    }
  }
  if(flag)
    cout << "YES";
  else
    cout <<"NO";
  return 0;
}