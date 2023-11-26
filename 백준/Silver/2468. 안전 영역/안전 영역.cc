#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int arr[101][101];
bool visited[101][101] = { false, };
int N;
int answer = 0;
int cnt = 0;
int water = 0;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
		if (arr[nx][ny] > water && !visited[nx][ny])
		{
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}
void clearVisited()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			visited[i][j] = false;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	for (int i = 0; i <=100; i++)
	{
		water = i;
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (arr[j][k] > water && !visited[j][k])
				{
					visited[j][k] = true;
					dfs(j, k);
					cnt++;
				}
			}
		}
		if (answer < cnt)answer = cnt;
		clearVisited();
		cnt = 0;
	}
	cout << answer;
	return 0;
}