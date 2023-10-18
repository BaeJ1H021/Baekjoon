#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int n,m;
int arr[51][51];
int cy[13]; //고른 치킨집. 
int cx[13]; //고른 치킨집.
vector<pair<int,int>> home; //집의 위치
vector<pair<int,int>> chicken; //치킨집의 위치.
int min_val = 987654321;
void dfs(int cnt,int id)
{
  if(cnt==m) //치킨집을 m개 고름.
  {
    int sum_distance =0;
    for(int i=0;i<home.size();i++)
    {
      int dist = 654321;
      for(int k=0;k<m;k++) //치킨집 전부 비교.
      {
        dist = min(dist, abs(cy[k]-home[i].first) + abs(cx[k]-home[i].second) );
      }
      sum_distance += dist; //최단거리 더하기.
    }
    min_val = min(min_val,sum_distance);
    return;
  }
  for(int i=id;i<chicken.size();i++)
  {
    cy[cnt] = chicken[i].first;
    cx[cnt] = chicken[i].second;
    dfs(cnt+1,i+1); //고른 치킨집 또 안고르기.
  }
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      cin >> arr[i][j];
      if(arr[i][j]==1) //집이면.
        home.push_back(make_pair(i,j));
      else if(arr[i][j]==2) //치킨집이면.
        chicken.push_back(make_pair(i,j));
    }
  
  dfs(0,0);
  cout << min_val;
  return 0;
}