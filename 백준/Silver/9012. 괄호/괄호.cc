#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string _case)
{
    stack<int> s;

    for(int i=0;i<_case.length();i++)
    {
        if(_case[i]=='(')
            s.push(1);
        else
        {
            if(s.empty())
            {
                return false;
            }
            s.pop();
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++)
    {
        string a = "";
        cin>>a;
        if(check(a)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}