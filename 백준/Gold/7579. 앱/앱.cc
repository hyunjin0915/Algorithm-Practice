using namespace std;

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int N, M;
    int totalCost = 0;
    vector<int> dp;
    int memory[101];
    int cost[101];
    
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>memory[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>cost[i];
        totalCost += cost[i];
    }
    dp.resize(totalCost+1, 0);
    
    for(int i = 0 ;i<N;i++)
    {
        for(int c = totalCost; c>= cost[i]; c--)
        {
            dp[c] = max(dp[c], dp[c - cost[i]] + memory[i]);   
        }
    }
    for(int c = 0; c<=totalCost;c++)
    {
        if(dp[c]>= M)
        {
            cout<<c<<'\n';
            break;
        }
    }
}