using namespace std;

#include <vector>
#include <iostream>

int N, M;
vector<int> arr;
vector<vector<bool>> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    arr.resize(N+1, 0);
    for(int i= 1;i<=N;i++)
    {
        cin>>arr[i];
    }
    
    dp.resize(N+1, vector<bool>(N+1, false));
    for(int i=1;i<=N;i++)
    {
        dp[i][i] = true;
    }
    for(int i=1;i<N;i++)
    {
        if(arr[i] == arr[i+1]) dp[i][i+1] = true;
    }
    
    for(int k=2;k<=N-1;k++)
    {
        for(int i=1;i<=N-k;i++)
        {
            int j = i + k;
            if(arr[i]==arr[j] && dp[i+1][j-1]) dp[i][j] = true;
        }
    }
    
    
    cin>>M;
    while(M--)
    {
        int S, E;
        cin>>S>>E;
        if(dp[S][E]) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}