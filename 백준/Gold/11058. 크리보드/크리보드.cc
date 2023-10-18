#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long dp[101] = {0,};
    int N;
    cin>>N;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    
    for(int i=7;i<=N;i++)
    {
        for(int j=3;j<i;j++)
        {
            dp[i] = max(dp[i], (j-1)*dp[i-j]);
        }
    }
    
    cout<<dp[N];
    return 0;
}