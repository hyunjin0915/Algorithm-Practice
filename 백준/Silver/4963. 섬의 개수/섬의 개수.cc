#include <iostream>
#include <memory.h>

using  namespace std;

int dx[8] = { 1,-1,0,0 ,-1,-1,1,1};
int dy[8] = { 0,0,1,-1,-1,1,-1,1};

int arr[51][51];
bool visited[51][51] = { false, };
int w, h;

int cnt = 0;

void dfs(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > h || ny > w) continue;
		if (arr[nx][ny] == 1 && !visited[nx][ny])
		{
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main()
{
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <=w; j++)
			{
				int num;
				cin >> num;
				visited[i][j] = false;
				arr[i][j] = num;
			}
		}
		cnt = 0;
	
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (arr[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = true;
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	memset(visited, false, sizeof(visited));
	}
	return 0;
}