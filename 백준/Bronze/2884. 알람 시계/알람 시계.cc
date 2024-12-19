#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int H,M;
  cin>> H >> M;
  if(M>=45)
    cout<< H << " " << M-45;
  else
  {
    if(H!=0)
      cout << H-1 << " " << M+15;
    else
      cout << 23 << " " <<M+15;
  }
  return 0;
}