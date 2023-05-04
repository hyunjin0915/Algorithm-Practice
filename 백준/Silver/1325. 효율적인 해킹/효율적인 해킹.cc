#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>>A;
static vector<int> answer;
static vector<bool> visited;

void BFS(int index);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long N,M;
    cin>>N>>M;
    A.resize(N+1);
    answer.resize(N+1);
    
    for(int i=0;i<M;i++)
    {
        int S,E;
        cin>>S>>E;
        A[S].push_back(E);
    }
    visited.resize(N+1);
    for(int i=0;i<=N;i++)
    {
        fill(visited.begin(),visited.end(),false);
        BFS(i);
    }
    int maxVal=0;
    for(int i=1;i<=N;i++)
        maxVal = max(maxVal, answer[i]);
    for(int i=1;i<=N;i++)
    {
        if(answer[i]==maxVal)
            cout<<i<<" ";
    }
    
    
}
void BFS(int index)
    {
        queue<int>q;
        q.push(index);
    visited[index]=true;
        while(!q.empty())
        {
            int now_node = q.front();
            q.pop();
            for(int i:A[now_node])
            {
                if(visited[i]==false)
                {
                    answer[i]++;
                q.push(i);
                    visited[i]=true;
                }
                
            }
        }
    }