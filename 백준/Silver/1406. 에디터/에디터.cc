using namespace std;
#include <iostream>
#include <list>

int main()
{
    list<char> lt;
    string str;
    cin>>str;
    
    for(int i=0;i<str.size();i++)
    {
        lt.push_back(str[i]);
    }
    
    list<char>::iterator iter = lt.end();
    
    int N;
    cin>>N;
    while(N--)
    {
        char c;
        cin>>c;
        if(c=='L')
        {
            if(iter != lt.begin()) iter--;
        }
        else if(c=='D')
        {
            if(iter != lt.end()) iter++;
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
    for(auto it: lt)
    {
        cout<<it;
    }
}