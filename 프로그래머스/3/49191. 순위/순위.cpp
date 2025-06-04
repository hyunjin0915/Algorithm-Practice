#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool winner[101][101] = {false};
    for(int i=0;i<results.size();i++)
    {
        winner[results[i][0]][results[i][1]] = true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(winner[j][i]==true && winner[i][k])
                {
                    winner[j][k] = true;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int temp = 0;
        for(int j=1;j<=n;j++)
        {
            if(winner[i][j] == true)
                temp++;
            if(winner[j][i] == true)
                temp++;
        }
        if(temp == n-1) answer++;
    }
    return answer;
}