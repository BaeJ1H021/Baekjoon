#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int ret= 1000;  //최솟값 찾기위한 변수.
  int y,x;
  cin >> y >> x;
  char board[y][x];
  for(int i=0;i<y;i++)
  {
    for (int j=0;j<x;j++)
    {
      cin >> board[i][j];
    }
  }
  //8x8로 다 세보기 case2가지.
  for(int i=0;i<y-7;i++)  //맨윗칸 
  {
    for(int j=0;j<x-7;j++)
    {
      int cnt1=0;
      int cnt2 = 0; //몇번 바꾸는지.
      for (int k=0;k<4;k++)
      {
        for (int l=0;l<4;l++)
        {
          //case 1 // W기준   
          if(board[i+2*k][j+2*l]=='B')
            cnt1++;
          if(board[i+2*k][j+2*l+1]=='W')
            cnt1++;
          if(board[i+2*k+1][j+2*l]=='W')
            cnt1++;
          if(board[i+2*k+1][j+2*l+1]=='B')
            cnt1++;
          //case 2 // B기준
          if(board[i+2*k][j+2*l]=='W')
            cnt2++;
          if(board[i+2*k][j+2*l+1]=='B')
            cnt2++;
          if(board[i+2*k+1][j+2*l]=='B')
            cnt2++;
          if(board[i+2*k+1][j+2*l+1]=='W')
            cnt2++;
        }
      }
      ret = min(ret,min(cnt1,cnt2));
    }
  }
  cout << ret;
  
  return 0;
}