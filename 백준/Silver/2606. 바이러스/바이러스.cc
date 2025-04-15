using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

void DFS(int node);

vector<vector<int>> vec;
vector<bool> visit;

int cnt = 0;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
   
    int N, M;
    cin>>N>>M;
    
    vec.resize(N+1);
    visit.resize(N+1, false);

    while(M--)
    {
        int u, v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    DFS(1);
    cout<<cnt-1;
}

void DFS(int node)
{
    cnt++;
    visit[node] = true;
    for(int i:vec[node])
    {
        if(!visit[i])
        {
            DFS(i);
        }
    }
}






