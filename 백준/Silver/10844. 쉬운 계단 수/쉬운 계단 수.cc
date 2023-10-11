#include <iostream>

using namespace std;

int main()
{
    long dp[101][10];
    
    for(int i=1;i<10;i++)
    {
        dp[0][i]=0;
        dp[1][i]=1;
    }
    
    int N;
    cin>>N;
    
    for(int i=2;i<=N;i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        
        for(int j=1;j<=8;j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    
    long sum = 0;
    
    for(int i=0;i<10;i++)
    {
        sum = (sum+dp[N][i])%1000000000;
    }
    
    cout<<sum;
}
