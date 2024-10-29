#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int size = land.size();
    int dp[size][4];
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    
    
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(j==0)
            {
                dp[i][j] = land[i][j] + max(max(dp[i-1][j+1],dp[i-1][j+2]),dp[i-1][j+3]);
            }
            else if(j==1)
            {
                dp[i][j] = land[i][j] + max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j+2]);
            }
            else if(j==2)
            {
                dp[i][j] = land[i][j] + max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j-2]);
            }
            else if(j==3)
            {
                dp[i][j] = land[i][j] + max(max(dp[i-1][j-1],dp[i-1][j-2]),dp[i-1][j-3]);
            }
        }
    }
    answer = dp[size-1][0];
    for(int i=1;i<4;i++)
    {
        if(answer<dp[size-1][i]) answer = dp[size-1][i];
    }
    return answer;
}