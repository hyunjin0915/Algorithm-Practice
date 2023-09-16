#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL
    );
    
    int T;
    cin>>T;
    
    
    string p="";
    string arr="";
    int n;
    
    bool isError = false;
    
    for(int i=0;i<T;i++)
    {
        deque<int> dq;
        bool way = true; 
        cin>>p;
        
        cin>>n>>arr;
        string tmp ="";
        
        for(int j=1;j<arr.length();j++)
        {
            if(n == 0) break;
            
            if(arr[j]==','||arr[j]==']')
            {
                if(tmp!="")
                {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
                
            }
            else
            {
                tmp+=arr[j];
            }
        }
        
        for(int k=0;k<p.length();k++)
        {
            if(p[k]=='R')
            {
                way = !way;
                continue;
            }
            else if(p[k]=='D')
            {
                if(dq.empty())
                {
                    cout<<"error"<<'\n';
                    isError = true;
                    break;
                }
                
                if(way)
                {
                    dq.pop_front();
                }
                else
                    dq.pop_back();
            }
        }
        if(isError)
        {
            isError = false;
            continue;
        }
        cout<<'[';
        
        if(!way) reverse(dq.begin(), dq.end());
        
        for(int k=0;k<dq.size();k++)
        {
            if(k==dq.size()-1) cout<<dq[k];
            else cout<<dq[k]<<",";
        }
        cout<<']'<<'\n';
    }
    
    return 0;
}