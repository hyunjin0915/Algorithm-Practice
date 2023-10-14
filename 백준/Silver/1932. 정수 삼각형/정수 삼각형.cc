#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long dp[500][500]={0,};
    
    int n;
    cin>>n;
    
    int k;
    cin>>k;
    dp[0][0] = k;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin>>k;
            
            if(j==0)
            {
                dp[i][j] = dp[i-1][0]+k;
            }
            else if(j==i)
            {
                dp[i][j] = dp[i-1][i-1]+k;
            }
            
            else
            {
                dp[i][j] = max(dp[i-1][j-1]+k,dp[i-1][j]+k);
            }
            
        }
    }
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        
        if(dp[n-1][i]>answer) answer = dp[n-1][i];
    }
    cout<<answer;
    return 0;
}