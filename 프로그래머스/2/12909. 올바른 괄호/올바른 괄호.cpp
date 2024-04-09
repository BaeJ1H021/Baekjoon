#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] =='(')
        {
            st.push('(');
        }
        else if(s[i] == ')')
        {
            if(st.empty())
                return false;
            else if(st.top() == '(')
                st.pop();
        }
    }
    return st.empty();
}