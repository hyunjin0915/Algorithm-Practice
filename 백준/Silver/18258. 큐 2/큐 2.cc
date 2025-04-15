using namespace std;
#include <iostream>

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int queue[2000001] = {0, };
    int front = 0;
    int rear = 0;
    
    int N;
    cin>>N;
    
    while(N--)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="push")
        {
            int k;
            cin>>k;
            queue[rear++] = k;
            continue;
        }
        else if(cmd=="pop")
        {
            if(rear==0 || front == rear)
            {
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<queue[front++]<<'\n';
         
            continue;
        }
        else if(cmd=="size")
        {
            cout<<rear - front<<'\n';
            continue;
        }
        else if(cmd=="empty")
        {
            if(front == rear) cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
            continue;
        }
        else if(cmd=="front")
        {
            if(front ==rear) cout<<"-1"<<'\n';
            else cout<<queue[front]<<'\n';
        }
        else if(cmd=="back")
        {
            if(front == rear) cout<<"-1"<<'\n';
            else cout<<queue[rear-1]<<'\n';
        }
    }
    return 0;
}