//테케는 맞는데 제출이 안됨..
//처음에는 bfs인가 했는데 수학문제처럼 dp를 활용하는 문제 

#include <vector>

using namespace std;

int MOD = 20170805;
#define down first
#define right second

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<pair<int, int>>> dp(m, vector<pair<int,int>>(n,{0, 0}));
    for(int i=1;i<m;i++)
    {
        if(city_map[i][0]==1) break;
        dp[i][0].down =1;
    }
    for(int i=1;i<n;i++)
    {
        if(city_map[0][i]==1) break;
        dp[0][i].right=1;
    }
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(city_map[i-1][j]==0) (dp[i][j].down = dp[i-1][j].down + dp[i-1][j].right) % MOD;
            if(city_map[i-1][j]==1) dp[i][j].down = 0;
            if(city_map[i-1][j]==2) dp[i][j].down = dp[i-1][j].down;
            
            if(city_map[i][j-1]==0) (dp[i][j].right = dp[i][j-1].right + dp[i][j-1].down) % MOD;
            if(city_map[i][j-1]==1) dp[i][j].right = 0;
            if(city_map[i][j-1]==2) dp[i][j].right = dp[i][j-1].right;
        }
    }
    
    if(m==1 && n==1) return 1;
    
    answer = (dp[m-1][n-1].down + dp[m-1][n-1].right) % MOD;
    
    return answer;
}