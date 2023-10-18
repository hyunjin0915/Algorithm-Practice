#include <iostream>
#include <cmath>

#define MAX 1500001
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int dp[MAX];
    int arr[MAX][2];
    
    for(int i=1;i<=N;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    
   int answer = 0;
    for(int i=1;i<=N+1;i++)
    {
        answer = max(answer, dp[i]);
        if(i+arr[i][0] > N+1) continue; //dp[8] = 1~7일동안 벌 수 있는 최대 액수
        dp[i+arr[i][0]] = max(answer + arr[i][1], dp[i+arr[i][0]]);
        
    }
    cout<<answer;
}