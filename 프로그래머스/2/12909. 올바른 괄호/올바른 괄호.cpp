#include<string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == '\(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty()) return false;
            if(st.top()!= '\(') return false;
            st.pop();
        }
    }
    if(st.empty()) return true;
    return false;
}