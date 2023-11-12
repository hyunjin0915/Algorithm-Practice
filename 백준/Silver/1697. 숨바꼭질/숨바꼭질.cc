#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

bool visited[100001];

int N, K;
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    BFS(N);
   
}

void BFS(int node)
{
    queue<pair<int, int>> q;
    q.push(make_pair(node,0));
    while (!q.empty())
    {
        int now_node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (now_node == K)
        {
            cout << cnt;
            break;
        }
        if (now_node + 1 < 100001 && now_node+1>=0)
        {
            if (!visited[now_node + 1])
            {
                visited[now_node + 1] = true;
                q.push(make_pair(now_node + 1,cnt+1));
            }
        }
        if (now_node - 1<100001 && now_node - 1 >= 0)
        {
            if (!visited[now_node - 1])
            {
                visited[now_node - 1] = true;
                q.push(make_pair(now_node - 1,cnt+1));
            }
        }
        if (now_node *2<100001 && now_node *2 >= 0)
        {
            if (!visited[now_node *2])
            {
                visited[now_node*2] = true;
                q.push(make_pair(now_node*2,cnt+1));
            }
        }
       
    }
}

