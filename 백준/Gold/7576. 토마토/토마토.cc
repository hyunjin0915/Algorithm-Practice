#include <iostream>
#include <queue>

using namespace std;

int m, n;
int box[1001][1001] = { 0, };
//int dist[1001][1001] = { 0, };

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue <pair<int, int>> qq;
int answer = 0;

void bfs()
{
	while (!qq.empty())
	{
		pair<int, int> cur = qq.front();
		qq.pop();
		int aa = cur.first;
		int bb = cur.second;
		
		for (int i = 0; i < 4; i++)
		{
			int na = aa + dx[i];
			int nb = bb + dy[i];
			if (na > 0 && nb > 0 && na <= n && nb <= m)
			{
				if (box[na][nb] == 0)
				{
					qq.push(make_pair(na, nb));
					box[na][nb] = box[aa][bb] + 1;
					//cout << box[na][nb]<<",";
				}
			}
		}

	}
}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int num;
			cin >> num;
			box[i][j] = num;
			if(num==1)	qq.push(make_pair(i, j));

		}
	}
	bfs();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			else if (answer < box[i][j])
				answer = box[i][j];
		}
	}
	cout << answer-1;
	return 0;
}