using namespace std;
#include <iostream>
#include <vector>
#include <queue>


#define INF 987654321

priority_queue<pair<int, int>> pq;

vector<vector<pair<int,int>>> vec;
vector<int> path;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int V, E, K;
    cin>>V>>E>>K;
    
    vec.resize(V+1);
    path.resize(V+1, INF);
    
    int a, b, c;
    while(E--)
    {
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
    }
    
    pq.push({0, K});
    path[K] = 0;
    
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        for(auto a : vec[cur])
        {
            if(path[a.first] > a.second + cost)
            {
                path[a.first] = a.second + cost;
                pq.push({ -path[a.first], a.first });
            }
        }
    }
    
    for(int i=1;i<=V;i++)
    {
        int p = path[i];
        if(i==K)
        {
            cout<<0<<'\n';
            continue;
        }
        if(p==INF)
        {
            cout<<"INF"<<'\n';
        }
        else
        {
            cout<<p<<'\n';
        }
    }
    return 0;
}