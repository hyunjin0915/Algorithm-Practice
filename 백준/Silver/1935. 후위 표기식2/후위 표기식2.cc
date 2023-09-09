#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main()
{
    stack<double> s;
    map<char,int> m;
    int N;
    cin>>N; //피연산자개수
    string st;
    cin>>st; //후위표기식
    
    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        m['A'+i] = num;
    }
    
    for(int i=0;i<st.length();i++)
    {
        if(st[i] >= 'A' && st[i] <='Z') //알파벳이면
        {
            s.push(m[st[i]]);
        }
        else //숫자또는기호이면
        {
            double temp = s.top();
            s.pop();
            if(st[i]=='+')
            {
                temp += s.top();
                
            }
            else if(st[i]=='-')
            {
                temp = s.top() - temp;
            }
            if(st[i]=='/')
            {
                temp = s.top() / temp;
                
            }
            if(st[i]=='*')
            {
                temp *= s.top();
                
            }
            
            s.pop();
            s.push(temp);
        }
       
    }
    cout<<fixed;
    cout.precision(2);
    cout<<s.top()<<endl;

    return 0;
}