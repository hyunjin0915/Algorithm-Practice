#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int arr[26][26];
bool visited[26][26] = { false, };
int N;
vector<int> answer;
int cnt = 0;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
		if (arr[nx][ny]=='1' && !visited[nx][ny])
		{
			visited[nx][ny] = true;
			cnt++;
			dfs(nx, ny);
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
			arr[i][j] = str[j-1];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j]=='1' && !visited[i][j])
			{
				cnt = 1;
				visited[i][j] = true;
				dfs(i, j);
				answer.push_back(cnt);
				
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (auto a:answer)
	{
		cout << a << '\n';
	}
	return 0;
}