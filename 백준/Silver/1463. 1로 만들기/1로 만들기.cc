#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    vector<int> Dp;
    Dp.resize(N+1);
    Dp[1]=0;
    
    for(int i=2;i<=N;i++)
    {
        Dp[i] = Dp[i-1]+1;
        if(i%2==0)
        {
            Dp[i] = min(Dp[i/2]+1,Dp[i]);
        }
        if(i%3==0)
        {
            Dp[i] = min(Dp[i/3]+1,Dp[i]);
        }
    }
    cout<<Dp[N];
}