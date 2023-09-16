#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    deque<int> dq;
    
    int left, right;
    int num, cnt = 0;
    
    for(int i=1;i<=N;i++)
    {
        dq.push_back(i);
    }
    
    for(int i=0;i<M;i++)
    {
        cin>>num;
        
        int index = 0;
        while(dq[index]!=num)
        {
            index++;
            left = index;
            right = dq.size()-index;
        }
        
        if(left<=right)
        {
            while(dq.front()!=num)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        else
        {
            //cnt++; 
            while(dq.front()!=num)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }
    
    cout<<cnt;
    return 0;
}