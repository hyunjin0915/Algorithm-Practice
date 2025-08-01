using namespace std;
#include <iostream>
#include <vector>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin>>N>>K;
    vector<pair<int, int>> bag;
    int dp[100001] = {0};
    
    while(N--)
    {
        int W, V;
        cin>>W>>V;
        bag.push_back({W, V});
    }
    for(int i=0;i<bag.size();i++)
    {
        auto [curW, curV] = bag[i];
        for(int j = K; j >= curW ; j--)
        {
            dp[j] = max(dp[j], dp[j-curW] + curV);
        }
    }
    cout<<dp[K];
    return 0;
}