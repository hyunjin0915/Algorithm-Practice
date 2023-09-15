#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    queue<int> q;
    
    int N,k;
    cin>>N;
    string cmd;
    
    for(int i=0;i<N;i++)
    {
        cin>>cmd;
        
        if(cmd=="push")
        {
            cin>>k;
            q.push(k);
            continue;
        }
        else if(cmd=="pop")
        {
            if(q.empty())
            {
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<q.front()<<'\n';
            q.pop();
            continue;
        }
        else if(cmd=="size")
        {
            cout<<q.size()<<'\n';
            continue;
        }
        else if(cmd=="empty")
        {
            if(q.empty()) cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
            continue;
        }
        else if(cmd=="front")
        {
            if(q.empty()) cout<<"-1"<<'\n';
            else cout<<q.front()<<'\n';
        }
        else if(cmd=="back")
        {
            if(q.empty()) cout<<"-1"<<'\n';
            else cout<<q.back()<<'\n';
        }
    }

    return 0;
}

