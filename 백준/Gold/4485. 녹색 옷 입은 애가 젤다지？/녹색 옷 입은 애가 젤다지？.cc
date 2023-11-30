#include <iostream>
#include <queue>

using namespace std;

int n;
int dp[125][125] = { 0, };
int arr[125][125] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs()
{
	priority_queue<pair<int, pair<int,int>>> pq;
	pq.push({ -1 * arr[0][0],{0,0} });
	dp[0][0] = arr[0][0];
	while (!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;

		pq.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)
			{
				if (dp[y][x] + arr[ny][nx] < dp[ny][nx])
				{
					dp[ny][nx] = dp[y][x] + arr[ny][nx];
					pq.push({ -1 * (dp[y][x] + arr[ny][nx]),{ny,nx} });
				}
			}
		}
	}
}

int main()
{
	int cnt = 1;
	while (true)
	{
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int num;
				cin >> num;
				arr[i][j] = num;
				dp[i][j] = 999999999;
			}
		}
		bfs();
		cout << "Problem "<<cnt<<": "<<dp[n - 1][n - 1] << '\n';
		cnt++;
	}
	return 0;
}