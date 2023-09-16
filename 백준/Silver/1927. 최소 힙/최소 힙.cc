#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    priority_queue<int, vector<int>, greater<>> pQ;
    
    int x;
    
    for(int i=0;i<N;i++)
    {
        cin>>x;
        if(x==0)
        {
            if(pQ.empty())
            {
                cout<<0<<'\n';
                continue;
            }
            cout<<pQ.top()<<'\n';
            pQ.pop();
        }
        else
        {
            pQ.push(x);
        }
    }
    
    return 0;
}