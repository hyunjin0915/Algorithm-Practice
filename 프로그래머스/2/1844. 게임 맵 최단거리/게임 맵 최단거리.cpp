#include<vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1 , 1};
int dy[4] = {1, -1,0,0};

int dist[101][101] = {0, };
bool visited[101][101] = {false, };
//void BFS(int a, int b);

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while(!q.empty())
    {
        int frontX = q.front().first;
        int frontY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = frontX + dx[i];
            int ny = frontY + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(maps[nx][ny] == 1 && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[frontX][frontY] + 1;
            }
            
        }
    }
    if(dist[N-1][M-1] == 0) return -1;
    return dist[N-1][M-1]+1;
}