#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<memory.h>
#include<vector>
#include<cmath>

using namespace std;

int main()                             
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
  string s;
  cin >> s;
  bool flag = false;
  int num = s[0] -'0'; //처음숫자.
  int ans = 0;
  for(int i=1;i<s.length();i++)
  {
    if(s[i]!='+' && s[i]!='-') //숫자면.
    {
      num = num * 10 + (s[i]-'0');
      //cout << num << "\n";
    }
    if( s[i]=='+' || s[i]=='-' || i == s.length()-1 ) //문자거나 마지막이면.
    {
      if(flag) //-가 한 번이라도 나오면 뒤에꺼 다 -.
      {
        ans -= num;
        num = 0;
      }
      else
      {
        ans += num;
        num = 0;
      }
      if(s[i]=='-')
      {
        flag = true;
      }
    }   
  }
  if(s.length()==1)
    cout << num;
  else
    cout << ans;
  return 0;
}