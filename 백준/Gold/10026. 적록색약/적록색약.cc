#include <iostream>
#include <algorithm>
#include <memory.h>

using  namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int arr[101][101] = { 0, };
bool visited[101][101] = { false, };
int N;

int cnt1 = 0;
int cnt2 = 0;
char curC;

void dfs1(int x, int y) 
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
		if (arr[nx][ny] == curC && !visited[nx][ny])
		{
			visited[nx][ny] = true;
			dfs1(nx, ny);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= N; j++)
		{
			visited[i][j] = false;
			arr[i][j] = str[j - 1];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = true;
				curC = arr[i][j];
				dfs1(i, j);
				cnt1++;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			visited[i][j] = false;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 'R') arr[i][j] = 'G';
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = true;
				curC = arr[i][j];
				dfs1(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2;
	return 0;
}