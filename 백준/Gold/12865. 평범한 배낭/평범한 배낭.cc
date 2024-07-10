#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K, W, V;
    cin >> N >> K;
    vector<pair<int, int>> vv;
    int dp[101][100001] = {0};  // dp 배열을 0으로 초기화

    for (int i = 0; i < N; i++)
    {
        cin >> W >> V;
        vv.push_back(make_pair(W, V));
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            int curW = vv[i - 1].first;
            int curV = vv[i - 1].second;
            if (curW <= j)
            {
                dp[i][j] = max(dp[i - 1][j], curV + dp[i - 1][j - curW]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K];

    return 0;
}
