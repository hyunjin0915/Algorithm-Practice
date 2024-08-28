#include <string>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<bool> visited;
void DFS(int v);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    A.resize(n);
    visited = vector<bool>(n,false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(computers[i][j]==1)
            {
                A[i].push_back(j);
                A[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            answer++;
            DFS(i);
        }
    }
    return answer;
}
void DFS(int v)
{
    if(visited[v]) return;
    visited[v] = true;
    
    for(int i : A[v])
    {
        if(visited[i]==false)
        {
            DFS(i);
        }
    }
}