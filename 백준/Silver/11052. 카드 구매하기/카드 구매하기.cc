#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int dp[1001] = {0,};
    int p[1001] = {0,};
    
    for(int i=1;i<=N;i++)
    {
        int k;
        cin>>k;
        p[i] = k;
    }
    
    dp[1] = p[1];
    dp[2] = max(p[1]+p[1],p[2]);
    dp[3] = max(dp[2] + p[1], p[3]);
    
    for(int i=4;i<=N;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            dp[i] = max(dp[i], dp[i-j] + p[j]);
        }
    }
    cout<<dp[N];
}