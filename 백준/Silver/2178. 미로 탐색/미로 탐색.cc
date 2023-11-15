#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[101][101] = { false, };
int dist[101][101] = { 0, };
int cnt = 0;
queue<pair<int, int>> q;

void bfs(int x, int y)
{
	visited[x][y] = true;
	q.push(make_pair(x, y));
	dist[x][y] = 1;
	while (!q.empty())
	{
		pair<int, int> now_node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
			{
				int nx = now_node.first + dx[i];
				int ny = now_node.second + dy[i];
				if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
				else
				{
					if (!visited[nx][ny] && arr[nx][ny] == 1)
					{
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true; //인접좌표방문처리
						dist[nx][ny] = dist[now_node.first][now_node.second]+1;
					}
				}
			}

	}
	cout << dist[n][m];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = str[j - 1]-'0';
		}
	}
	bfs(1, 1);
	return 0;
}