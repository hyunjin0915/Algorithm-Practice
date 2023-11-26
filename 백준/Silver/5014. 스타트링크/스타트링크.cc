#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

bool visited[1000001] = { false, };
int f, s, g, u, d;
void BFS(int node);
bool success = false;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;
    visited[s] = true;
    BFS(s);
    if (!success) cout << "use the stairs";
}

void BFS(int node)
{
    queue<pair<int, int>> q;
    q.push(make_pair(node, 0));
    while (!q.empty())
    {
        int now_node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (now_node == g)
        {
            cout << cnt;
            success = true;
            break;
        }
        if (now_node + u <= f)
        {
            if (!visited[now_node + u])
            {
                visited[now_node + u] = true;
                q.push(make_pair(now_node + u, cnt + 1));
            }
        }
        if (now_node - d > 0)
        {
            if (!visited[now_node - d])
            {
                visited[now_node - d] = true;
                q.push(make_pair(now_node - d, cnt + 1));
            }
        }

    }
}