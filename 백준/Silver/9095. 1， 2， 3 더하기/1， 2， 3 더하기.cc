#include <iostream>

using namespace std;

int dp[12] = {0,};

int main()
{
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    int T;
    cin>>T;
    for(int i=4;i<12;i++)
    {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        cout<<dp[N]<<'\n';
    }
}