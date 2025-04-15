using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

void DFS(int node);

vector<vector<int>> vec;
vector<bool> visit;
vector<int> answer;

int cnt = 1;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
   
    int N, M, R;
    cin>>N>>M>>R;
    
    vec.resize(N+1);
    visit.resize(N+1, false);
    answer.resize(N+1,0);
    while(M--)
    {
        int u, v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for(int i=0;i<vec.size();i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    DFS(R);
    for(int i=1;i<=N;i++)
    {
        cout<<answer[i]<<'\n';
    }
    
}

void DFS(int node)
{
    visit[node] = true;
    answer[node] = cnt++;
    
    for(auto i : vec[node])
    {
        if(!visit[i])
        {
            DFS(i);
        }
    }
}


