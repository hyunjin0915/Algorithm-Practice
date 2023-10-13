#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int Stair[310]={0,};
    int dp[310]={0,};
    
    for(int i=1;i<=N;i++)
    {
        int k;
        cin>>k;
        Stair[i]=k;
    }
    dp[1] = Stair[1];
    dp[2] = Stair[1]+Stair[2];
    for(int i=3;i<=N;i++)
    {
        dp[i]=max(dp[i-3]+Stair[i]+Stair[i-1], dp[i-2]+Stair[i]);
    }
    cout<<dp[N]<<'\n';
}