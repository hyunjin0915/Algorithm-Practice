#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<char> lt;
    string st;
    cin>>st;
    for(int i=0;i<st.length();i++)
    {
        lt.push_back(st[i]);
    }
    list<char>::iterator iter = lt.end();
    
    int M;
    cin>>M;
    char c;
    for(int i=0;i<M;i++)
    {
        cin>>c;
        if(c=='L')
        {
            if(iter!=lt.begin()) iter--;
        }
        else if(c=='D')
        {
            if(iter!=lt.end()) iter++;
        }
        else if(c=='B')
        {
            if(iter!=lt.begin()) iter = lt.erase(--iter);
        }
        else if(c=='P')
        {
            char add;
            cin>>add;
            lt.insert(iter, add);
        }
    }
    for(auto it : lt)
    {
        cout<<it;
    }
}