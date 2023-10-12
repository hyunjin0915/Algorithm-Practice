#include <iostream>

using namespace std;

int main()
{
    long long dp[1001][10];
    
    int N;
    cin>>N;
    
    
    for(int i=0;i<10;i++)
    {
        dp[1][i] = 1;
        dp[0][i]= 0;
    }
    for(int i=2;i<=N;i++)
    {
        dp[i][0]=1;
        
        for(int j = 1;j<=9;j++)
        {
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%10007;
        }
    }
    long long answer = 0;
    for(int i=0;i<=9;i++)
    {
        answer+=dp[N][i];
        answer%=10007;
    }
    cout<<answer%10007;
    return 0;
}