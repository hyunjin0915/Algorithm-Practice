#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> dp(501,vector<int>(501,0));
    int tS = triangle.size();
  
    dp[0][0] = triangle[0][0];
    answer = dp[0][0];
    for(int i=1;i<triangle.size();i++)
    {
        dp[i][0] = triangle[i][0] + dp[i-1][0];
        dp[i][i] = triangle[i][i] + dp[i-1][i-1];
        for(int j=1;j<triangle[i].size()-1;j++)
        {
            int m = (dp[i-1][j-1] > dp[i-1][j])?dp[i-1][j-1]:dp[i-1][j] ;
            dp[i][j] = triangle[i][j] + m;
            
        }
    }
    for(int i=0;i<tS;i++)
    {
        if(answer<dp[tS-1][i]) answer = dp[tS-1][i] ; 
    }
    return answer;
}