using namespace std;
#include <iostream>
#include <queue>

int n, m;
int map[501][501];
bool visited[501][501] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int BFS(int sy, int sx)
{
    int space = 0;
    queue<pair<int, int>> q;
    q.push({sy,sx});
    visited[sy][sx] = true;
    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        space++;
        for(int i=0;i<4;i++)
        {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];
            if(nx<0 || ny<0 || nx >=m || ny>=n) continue;
            if(visited[ny][nx] || map[ny][nx] == 0) continue;
            
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    return space;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            
        }
    }
    
    int cnt = 0;
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==1 && !visited[i][j])
            {
                int space = BFS(i, j);
                answer = max(answer, space);
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n'<<answer;
}