/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[100000];
    int dp[100000];
    
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        arr[i]=k;
    }
    int answer = arr[0];
    dp[0] = arr[0];
    
    for(int i=1;i<n;i++)
    {
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        answer = max(answer, dp[i]);
    }
    cout<<answer;
}