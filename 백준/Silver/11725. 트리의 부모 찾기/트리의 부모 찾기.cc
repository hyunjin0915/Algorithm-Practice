#include <iostream>
#include <vector>
using  namespace std;

vector<vector<int>> v;
vector<vector<int>> answer;
vector<bool> visited;
void DFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    v.resize(N+1);
    answer.resize(N+1);
    visited = vector<bool>(N + 1, false);
    for (int i = 0; i < N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    for (int i = 2; i <= N; i++)
    {
        cout << answer[i][0] << '\n';
    }
}

void DFS(int node)
{
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (!visited[v[node][i]])
        {
            answer[v[node][i]].push_back(node);
            DFS(v[node][i]);
        }
    }
}