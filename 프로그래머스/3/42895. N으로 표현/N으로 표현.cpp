#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<set<int>> dp(9);
    int num = 0;
    for(int i=1;i<=8;i++)
    {
        num = N + 10*num;
        dp[i].insert(num);
    }
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(auto a : dp[j])
            {
                for(auto b : dp[i-j])
                {
                    dp[i].insert( a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b!=0) dp[i].insert(a/b);
                }
            }
            
        }
        if(dp[i].find(number) != dp[i].end()) return i;
    }
    return -1;
}