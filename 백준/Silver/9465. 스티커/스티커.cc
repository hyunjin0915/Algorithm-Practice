#include <iostream>
#include <cmath>
#define maxN 100000
using namespace std;

int main()
{
    int buf[2][maxN+1] = {0,};
    int dp[2][maxN+1] = {0,};
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        
        int num;
        for(int j=0;j<n;j++)
        {
            cin>>num;
            buf[0][j] = num;
        }
        for(int j=0;j<n;j++)
        {
            cin>>num;
            buf[1][j] = num;
        }
        
        dp[0][0] = buf[0][0];
        dp[1][0] = buf[1][0];
        dp[0][1] = buf[0][1] + dp[1][0];
        dp[1][1] = buf[1][1] + dp[0][0];
        
        for(int j=2;j<n;j++)
        {
            dp[0][j] = buf[0][j] + max(dp[1][j-2], dp[1][j-1]);
            dp[1][j] = buf[1][j] + max(dp[0][j-2], dp[0][j-1]);
        }
        
        cout<<max(dp[0][n-1],dp[1][n-1])<<'\n';
    }
    
}