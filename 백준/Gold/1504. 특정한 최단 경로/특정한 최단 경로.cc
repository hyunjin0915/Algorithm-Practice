using namespace std;
#include <iostream>
#include <vector>
#include <queue>


#define INF 987654321

vector<vector<pair<int, int>>> vec;
    vector<int> path1;
    vector<int> path2;
    vector<int> path3;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int N,E,v1,v2;
    cin>>N>>E;
    vec.resize(N+1);
    path1.resize(N+1, INF);
    path2.resize(N+1, INF);
    path3.resize(N+1, INF);
    
    while(E--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    cin>>v1>>v2;
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    path1[1] = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(auto a : vec[cur])
        {
            if(path1[a.first] > cost + a.second)
            {
                path1[a.first] = cost + a.second;
                pq.push({-path1[a.first] , a.first});
            }
        }
    }
    pq.push({0,v1});
    path2[v1] = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(auto a : vec[cur])
        {
            if(path2[a.first] > cost + a.second)
            {
                path2[a.first] = cost + a.second;
                pq.push({-path2[a.first] , a.first});
            }
        }
    }
    pq.push({0,v2});
    path3[v2] = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(auto a : vec[cur])
        {
            if(path3[a.first] > cost + a.second)
            {
                path3[a.first] = cost + a.second;
                pq.push({-path3[a.first] , a.first});
            }
        }
    }
    if(path1[v1]==INF || path1[v2]==INF || 
   path2[v2]==INF || path2[N]==INF ||
   path3[v1]==INF || path3[N]==INF)
    {
        cout<<-1;
        return 0;
    }
    
    int answer = min((path1[v1] + path2[v2] + path3[N]),(path1[v2] + path3[v1] + path2[N]));
    cout<< answer;
    

}