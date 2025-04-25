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

string arr[100001];

int main()                             
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n,m;
  map<string,int> ms;
  
  cin >> n >> m;
  for(int i=1;i<=n;i++)
  {
    string str;
    cin >> str;
    arr[i] = str;
    ms.insert({str,i});
  }

  for(int i=1;i<=m;i++)
  {
    string str;
    cin >> str;
    if(str[0] < 'A')
      cout << arr[stoi(str)] << "\n";
    else
      cout << ms[str] << "\n";
  }
  return 0;
} 