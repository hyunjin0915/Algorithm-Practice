#include<vector>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;
    Node(int _x, int _y) : x(_x), y(_y){}
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
vector<vector<bool>> visited;
vector<vector<int>> dp;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    visited.resize(n, vector<bool>(m , false));
    dp.resize(n , vector<int>(m, 0));
    
    queue<Node>q;
    q.push(Node(0,0));
    visited[0][0] = true;
    dp[0][0] = 1;
    
    while(!q.empty())
    {
        Node node = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny >=m) continue;
            if(maps[nx][ny] == 0 || visited[nx][ny]) continue;
            q.push(Node(nx, ny));
            dp[nx][ny] = dp[node.x][node.y] + 1;
            visited[nx][ny] = true;
        }
    }
    
    return dp[n-1][m-1] == 0 ? -1 : dp[n-1][m-1];
}