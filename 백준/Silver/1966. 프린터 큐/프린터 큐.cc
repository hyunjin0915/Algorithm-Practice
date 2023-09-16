#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T; //테케수
    int cnt = 0;
    int N,M, num;
    
    for(int i=0;i<T;i++)
    {
        cnt = 0;
        cin>>N>>M;
        queue<pair<int, int>>  q;
        priority_queue<int> pq;
        
        for(int j=0;j<N;++j)
        {
            cin>>num;
            q.push({j,num });
            pq.push(num);
        }
        while(!q.empty())
        {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top()==value)
            {
                pq.pop();
                ++cnt;
                if(index==M)
                {
                    cout<<cnt<<'\n';
                    break;
                }
            }
            else q.push({index, value});
        }
    }
}