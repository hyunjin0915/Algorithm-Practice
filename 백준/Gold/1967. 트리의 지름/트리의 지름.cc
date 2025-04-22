using namespace std;
#include <iostream>
#include <vector>
#include<memory.h>

vector<pair<int, int>> vec[10001];
vector<bool> visited;

int sum = 0;
int answer = 0;
int DFS(int node)
{
    visited[node] = true;
    for(auto a : vec[node])
    {
        if(!visited[a.first])
        {
            sum+=a.second;
            visited[a.first] = true;
            answer = max(answer, sum);
            DFS(a.first);
            sum-=a.second;
        }
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;

    visited.resize(n+1, false);
    
    for(int i=1;i<n;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    
    for(int i=1;i<=n;i++)
    {
        DFS(i);
        for(int j=1;j<=n;j++)
        {
            visited[j]=false;
        }
    }
    
    cout<<answer;
    
    
    
    return 0;
}