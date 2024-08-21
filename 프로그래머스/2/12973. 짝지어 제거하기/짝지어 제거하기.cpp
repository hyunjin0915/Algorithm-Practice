#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    if(s.size()==1) return 0;
    stack<char> st;
    st.push(s[0]);
    for(int i=1;i<s.size();i++)
    {
        if(!st.empty() && s[i]==st.top())
        {
            st.pop();
        }
        else if(st.empty() || s[i]!=st.top())
        {
            st.push(s[i]);
        }
    }
    if(st.empty())
        return 1;
    else
        return 0;
}