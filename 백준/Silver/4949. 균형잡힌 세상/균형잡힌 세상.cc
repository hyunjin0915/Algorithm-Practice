using namespace std;
#include <iostream>
#include <stack>
#include <string>

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    
    while(true)
    {
        string str = "";
        getline(cin, str);
        if(str==".") break;
        
        stack<char> stack;
        bool b = true;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '[' || str[i] == '(')
            {
                stack.push(str[i]);
            }
            else if(str[i] == ']')
            {
                if(!stack.empty())
                {
                    if(stack.top() == '[')
                    {
                        stack.pop();
                    }
                    else b = false;
                    continue;
                }
                b = false;
            }
            else if(str[i] == ')')
            {
                if(!stack.empty())
                {
                    if(stack.top() == '(')
                    {
                        stack.pop();
                    }
                    else b = false;
                    continue;
                }
                b = false;
            }
        }
        if(stack.empty()&&b)
        {
            cout<<"yes"<<'\n';
        }
        else
        {
            cout<<"no"<<'\n';
        }
    }
}