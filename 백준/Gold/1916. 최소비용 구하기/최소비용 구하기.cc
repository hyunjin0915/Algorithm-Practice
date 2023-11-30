#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int wS, wE;
int dp[1001];
vector<pair<int,int>> costs[1001];

void bfs(int _start)
{
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0,_start }); 

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > dp[cur]) continue;
		for (int i = 0; i < costs[cur].size(); i++)
		{
			int next = costs[cur][i].first;
			int nextCost = dp[cur] + costs[cur][i].second;

			if (nextCost < dp[next])
			{
				dp[next] = nextCost;
				pq.push({ nextCost, next });
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		costs[start].push_back(make_pair(end, cost));
	}
	cin >> wS >> wE;
	fill_n(dp, 1001, 999999999);
	dp[wS] = 0;
	bfs(wS);
	cout << dp[wE];
	return 0;
}