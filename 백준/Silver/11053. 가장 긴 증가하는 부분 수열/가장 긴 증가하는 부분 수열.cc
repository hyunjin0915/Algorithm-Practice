/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    int arr[1001];
    int dp[1001];
    
    cin>>N;
    int answer = 0;
    
    for(int i=1;i<=N;i++)
    {
        int x;
        cin>>x;
        arr[i] = x;
    }
    
    for(int i=1;i<=N;i++)
    {
        dp[i]=1;
        for(int j=i-1;j>=1;j--)
        {
            if(arr[i]>arr[j])
                {dp[i] = max(dp[j]+1,dp[i]);}
        }
        answer = max(answer,dp[i]);
    }

    cout<<answer;
    return 0;
}