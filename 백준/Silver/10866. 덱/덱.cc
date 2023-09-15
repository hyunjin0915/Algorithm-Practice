#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,k;
    string cmd;
    deque <int> dq;
    
    cin>>N;
    
   
    for(int i=0;i<N;i++)
    {
        cin>>cmd;
    
    
    if(cmd=="push_front")
    {
        cin>>k;
        dq.push_front(k);
    }
    else if(cmd=="push_back")
    {
        cin>>k;
        dq.push_back(k);
    }
    else if(cmd=="pop_front")
    {
        if(dq.empty()) {
            cout<<"-1"<<'\n';
            continue;}
        cout<<dq.front()<<'\n';
        dq.pop_front();
    }
    else if(cmd=="pop_back")
    {
        if(dq.empty()) {
            cout<<"-1"<<'\n';
            continue;}
        cout<<dq.back()<<'\n';
        dq.pop_back();
    }
    else if(cmd=="size")
    {
        cout<<dq.size()<<'\n';
    }
    else if(cmd=="empty")
    {
        if(dq.empty()) cout<<"1"<<'\n';
        else cout<<"0"<<'\n';
    }
    else if(cmd=="front")
    {
        if(dq.empty()) cout<<"-1"<<'\n';
        else cout<<dq.front()<<'\n';
    }
    else if(cmd=="back")
    {
        if(dq.empty()) cout<<"-1"<<'\n';
        else cout<<dq.back()<<'\n';
    }
    }
}