using namespace std;
#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

vector<int> path;
int N, K;
priority_queue<pair<int, int>> pq;

bool Check(int num)
{
    if(num<0||num>100000) return false;
    return true;
}

void BFS()
{
    pq.push({0, N});
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cur==K) return;
        
        int n1 = cur -1;
        int n2 = cur +1;
        int n3 = cur * 2;
        if(Check(n1))
        {
            if(path[n1] > cost + 1)
            {
                path[n1] = cost + 1;
                pq.push({-(cost+1), n1});
            }
            
        }
        if(Check(n2))
        {
            if(path[n2] > cost + 1)
            {
                path[n2] = cost + 1;
                pq.push({-(1+cost), n2});
            }
            
        }
        if(Check(n3))
        {
            if(path[n3] > cost)
            {
                path[n3] = cost;
                pq.push({-(cost), n3});
            }

        }

    }
}




int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N>>K;
    path.resize(100001,INF);

    path[N] = 0;
    BFS();
    
    cout<<path[K];
}

