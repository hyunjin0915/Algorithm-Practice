#include <iostream>
#include <memory.h>

using namespace std;

const int MAX = 1001;
void BFS(int n);
int A[MAX];
bool visited[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int answer = 0;
		int N;
		cin >> N;
		
		for (int j = 1; j <= N; j++)
		{
			int M;
			cin >> M;
			A[j] = M;
		}

		for (int j = 1; j <= N; j++)
		{
			if (visited[j]) continue;
			else 
			{
				BFS(j);
				answer++;
			}
		}
		cout << answer << '\n';
		memset(visited, false, sizeof(visited));
	}
}

void BFS(int n)
{
	visited[n] = true;
	int num = A[n];
	if (!visited[num])
		BFS(num);
	if (visited[n])
		return;

}