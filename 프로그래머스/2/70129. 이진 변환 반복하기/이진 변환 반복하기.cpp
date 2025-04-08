#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;    
    int b = 0;
    int cnt = 0;  
    stack<int> st;
    while(true)
    {   
        int a = 0;
        string str="";
        cnt++;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                b++;
                continue;
            }
            a++;
        }
        while(a!=0)
        {
            if(a%2 == 1)
            {
                st.push(1);
            }
            else
            {
                st.push(0);
            }
            a/=2;
            
        }
        while(!st.empty())
        {
            str += (st.top()+'0');
            st.pop();
        }

       if(str=="1") break;
        s = str;
    }

    answer.push_back(cnt);
    answer.push_back(b);
    return answer;
}