#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

int n,m;
int arr[9][9];
int copy_arr[9][9];
int min_val =100;
vector<pair<int,int>> cctv[5];
int direction[5][8];
void left(int num, int order) //왼쪽으로 쏘기.
{         //cctv번호 ,몇번째 cctv인지.
  for(int j=cctv[num][order].second-1;j>=0;j--)
  {
    if(arr[cctv[num][order].first][j]==0)
      arr[cctv[num][order].first][j] = -1;
    else if(arr[cctv[num][order].first][j]==6)
      break;
  }
}
void right(int num, int order)
{
  for(int j=cctv[num][order].second+1;j<m;j++)
  {
    if(arr[cctv[num][order].first][j]==0)
      arr[cctv[num][order].first][j] = -1;
    else if(arr[cctv[num][order].first][j]==6)
      break;
  }
}
void up(int num, int order)
{
  for(int j=cctv[num][order].first-1;j>=0;j--)
  {
    if(arr[j][cctv[num][order].second]==0)
      arr[j][cctv[num][order].second] = -1;
    else if(arr[j][cctv[num][order].second] ==6)
      break;
  }
}
void down(int num, int order)
{
  for(int j=cctv[num][order].first+1;j<n;j++)
  {
    if(arr[j][cctv[num][order].second]==0)
      arr[j][cctv[num][order].second] = -1;
    else if(arr[j][cctv[num][order].second] ==6)
      break;
  }
}
void dfs(int id1,int id2,int id3,int id4,int id5)
{
  memcpy(copy_arr,arr,sizeof(arr));
  //cctv가 보는 방향 다 정해야함.
  if(id1 < cctv[0].size())
  {
    direction[0][id1] = 4; //왼쪽
    dfs(id1+1,id2,id3,id4,id5);
    direction[0][id1] = 6; //오른쪽
    dfs(id1+1,id2,id3,id4,id5);
    direction[0][id1] = 8; //윗쪽
    dfs(id1+1,id2,id3,id4,id5);
    direction[0][id1] = 2; //아랫쪽
    dfs(id1+1,id2,id3,id4,id5);
    return;
  } 
  else if(id2<cctv[1].size())
  {
    direction[1][id2] = 4; //좌우
    dfs(id1,id2+1,id3,id4,id5);
    direction[1][id2] = 8; //상하
    dfs(id1,id2+1,id3,id4,id5);
    return;
  }
  else if(id3<cctv[2].size())
  {
    direction[2][id3] = 4; //  좌상
    dfs(id1,id2,id3+1,id4,id5);
    direction[2][id3] = 6; //  우하
    dfs(id1,id2,id3+1,id4,id5);
    direction[2][id3] = 8; //  우상
    dfs(id1,id2,id3+1,id4,id5);
    direction[2][id3] = 2; //  좌하
    dfs(id1,id2,id3+1,id4,id5);
    return;
  }
  else if(id4<cctv[3].size())
  {
    direction[3][id4] = 4; //왼쪽만빼고
    dfs(id1,id2,id3,id4+1,id5);
    direction[3][id4] = 6; //오른쪽만뺴고
    dfs(id1,id2,id3,id4+1,id5);
    direction[3][id4] = 8; //윗쪽뻬고
    dfs(id1,id2,id3,id4+1,id5);
    direction[3][id4] = 2; //아랫쪽빼고
    dfs(id1,id2,id3,id4+1,id5);
    return;
  }
  else if(id5<cctv[4].size())
  {
    direction[4][id5] = 4; //상하좌우
    dfs(id1,id2,id3,id4,id5+1);
    return;
  }
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<cctv[i].size();j++)
    {
      if(direction[i][j] == 4)
      {
        if(i==0)
        {
          left(i,j);
        }
        else if(i==1)
        {
          left(i,j);
          right(i,j);
        }
        else if(i==2)
        {
          left(i,j);
          up(i,j);
        }
        else if(i==3)
        {
          right(i,j);
          up(i,j);
          down(i,j);
        }
        else if(i==4)
        {
          left(i,j);
          right(i,j);
          up(i,j);
          down(i,j);
        }
      }
      else if(direction[i][j]==6) 
      {
        if(i==0)
        {
          right(i,j);
        }
        else if(i==2)
        {
          right(i,j);
          down(i,j);
        }
        else if(i==3)
        {
          left(i,j);
          up(i,j);
          down(i,j);
        }
      }
      else if(direction[i][j]==8) 
      {
        if(i==0)
        {
          up(i,j);
        }
        else if(i==1)
        {
          up(i,j);
          down(i,j);
        }
        else if(i==2)
        {
          right(i,j);
          up(i,j);
        }
        else if(i==3)
        {
          left(i,j);
          right(i,j);
          down(i,j);
        }
      }
      else if(direction[i][j]==2) 
      {
        if(i==0)
        {
          down(i,j);
        }
        else if(i==2)
        {
          left(i,j);
          down(i,j);
        }
        else if(i==3)
        {
          left(i,j);
          right(i,j);
          up(i,j);
        }
      }
    }
  }

  int result = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]==0)
        result++;
    }
  }
  
  min_val = min(min_val,result);
  memcpy(arr,copy_arr,sizeof(arr));
}
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> arr[i][j];
      if(arr[i][j] == 1)
        cctv[0].push_back(make_pair(i,j));
      else if(arr[i][j] == 2)
        cctv[1].push_back(make_pair(i,j));
      else if(arr[i][j] == 3)
        cctv[2].push_back(make_pair(i,j));
      else if(arr[i][j] == 4)
        cctv[3].push_back(make_pair(i,j));
      else if(arr[i][j] == 5)
        cctv[4].push_back(make_pair(i,j));
    }
  }
  dfs(0,0,0,0,0);
  cout <<min_val;
  
  return 0;
}