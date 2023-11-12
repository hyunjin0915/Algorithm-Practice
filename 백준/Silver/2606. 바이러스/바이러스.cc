#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

static vector<vector <int>>A;
static vector<bool> visited; 
int answer = 0;
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    visited = vector<bool>(N + 1, false);
    BFS(1);
    cout << answer-1;
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int now_node = q.front();
        q.pop();
        answer++;
        for (int j = 0; j < A[now_node].size(); j++)
        {
            if (!visited[A[now_node][j]]) 
            {
                visited[A[now_node][j]] = true;
                q.push(A[now_node][j]);
            }
        }
    }
}