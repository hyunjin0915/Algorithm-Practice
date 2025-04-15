using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

void BFS(int node);

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
    
    BFS(R);
    
    for(int i=1;i<=N;i++)
    {
        cout<<answer[i]<<'\n';
    }
    
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visit[node] = true;
    while(!q.empty())
    {
        int now_node = q.front();
        q.pop();
        answer[now_node] = cnt++;
        for(auto i : vec[now_node])
        {
            if(!visit[i])
            {
                visit[i] = true;
                q.push(i);
            }
            
        }
    }
}


