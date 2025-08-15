#include <string>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> subtree;

int answer = -1;
int n;

int DFS(int u, int parent)
{
    subtree[u]=1;
    for(int w : g[u])
    {
        if(w == parent) continue;
        int cnt = DFS(w, u);
        answer = min(answer, abs(cnt*2 - n));
        subtree[u] += cnt;
    }
    return subtree[u];
}

int solution(int N, vector<vector<int>> wires) {
    answer = N;
    n=N;
    g.resize(n+1);
    subtree.resize(n+1);
    
    for(auto w : wires)
    {
        g[w[0]].push_back(w[1]);
        g[w[1]].push_back(w[0]);
    }
    
    DFS(1, 0);
    
    return answer;
}