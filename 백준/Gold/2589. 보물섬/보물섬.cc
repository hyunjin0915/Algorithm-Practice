#include <iostream>
#include <queue>
#define Max 51

using namespace std;

bool map[Max][Max] = { false, };
bool visited[Max][Max] = { false, };
int cnt[Max][Max];
int dist[Max][Max] = { 0, };
int w, h;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int answer = 0;

int bfs(int a, int b)
{
	int max = 0;
	visited[a][b] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(a, b));
	dist[a][b] = 1;
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int na = p.first+dx[i];
			int nb = p.second+dy[i];

			if (na <= 0 || nb <= 0 || na > h || nb > w) continue;
			else
			{
				if (!visited[na][nb] && map[na][nb])
				{
					dist[na][nb] = dist[p.first][p.second] + 1;
					if (dist[na][nb] > max) max = dist[na][nb];
					q.push(make_pair(na, nb));
					visited[na][nb] = true;
				}
			}
		}
	}
	return max;
}

void clearVisited()
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			visited[i][j] = false;
			dist[i][j] = 0;
		}
	}
}
int main()
{
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= w; j++)
		{
			char c = str[j - 1];
			map[i][j] = (c == 'W' ? false : true);
		}
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (map[i][j])
			{
				cnt[i][j]=bfs(i, j);
				if (answer < cnt[i][j]) answer = cnt[i][j];
				clearVisited();
			}
			else continue;
		}
	}
	cout << answer - 1;
}