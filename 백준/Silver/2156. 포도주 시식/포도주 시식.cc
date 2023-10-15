#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int arr[10001]={0,};
    long long dp[10001]={0,};

    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        arr[i] = num;
    }
    
    
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3] = max(arr[1]+arr[3],arr[2]+arr[3]);
    
    int answer = 0;
    for(int i=4;i<=n;i++)
    {
        if(i==4)
        {
            dp[i] = max(dp[i-2], arr[i-1] + dp[i-3]) + arr[i];
            continue;
        }
        dp[i] = max(max(arr[i-1] + dp[i-3],dp[i-2]), arr[i-1]+dp[i-4]) + arr[i];

    }
    for(int i=1;i<=n;i++)
    {
        if(answer<dp[i]) answer = dp[i];
    }
    cout<<answer;
    
}