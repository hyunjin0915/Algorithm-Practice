#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin>>N>>K;
    
    int dp[201][201]={0,};
    
    for(int i=1;i<=N;i++)
    {
        dp[1][i]=1;
    }
    for(int i=1;i<=K;i++)
    {
        dp[i][1] = i;
    }
    for(int i=2;i<=K;i++)
    {
        for(int j=2;j<=N;j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) %1000000000;
        }
    }
    cout<<dp[K][N];
}