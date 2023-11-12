#include <iostream>
#include <vector>


using  namespace std;

bool visited[501] = { false, };
vector<vector<int>> v;
int answer = 0;

void DFS(int node, int depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    v.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[1] = true;
    DFS(1, 0);
    for (int i = 2; i <=n; i++)
    {
        if (visited[i]) answer++;
    }
   
    cout << answer;
}

void DFS(int node, int depth)
{
    if (depth == 2)
    {
        return;
    }
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        visited[next] = true;
        DFS(next, depth + 1);
    }
}