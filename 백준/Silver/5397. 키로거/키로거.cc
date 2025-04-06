using namespace std;
#include <iostream>
#include <list>

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string str;
        cin>>str;
        
        list<char> lt;
        list<char>::iterator iter = lt.begin();
        
        for(int i=0;i<str.size();i++)
        {
            if((str[i]=='<'))
            {
                if(iter != lt.begin())
                {
                    iter--;                   
                }
                continue;
            }
            if((str[i]=='>'))
            {
                if(iter != lt.end())
                {
                    iter++;                  
                }
                continue;
            }
            if((str[i]=='-'))
            {
                if(iter!=lt.begin())
                {
                    iter--;
                    iter = lt.erase(iter);
                    /*iter = lt.erase(--iter);
                    continue;*/
                }
                continue;
            }
            else
            {
                lt.insert(iter,str[i]);
            }
        }
        for(auto it: lt)
        {
            cout<<it;
        }
        cout<<'\n';
    }
    
}