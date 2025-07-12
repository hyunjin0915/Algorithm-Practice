using namespace std;

#include <iostream>
#include <vector>
#include <queue>

vector<vector<int>> north;
vector<vector<int>> temp;
vector<vector<bool>> visited;
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int BFS()
{
    int num = 0;
    for (int i = 0; i < N; i++) {
        fill(visited[i].begin(), visited[i].end(), false);
    }
    
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (!visited[i][j] && north[i][j] > 0) 
            {
                num++;
                visited[i][j] = true;
                q.push({i, j});
                
                while(!q.empty())
                {
                    auto node = q.front();
                    q.pop();
                    
                    for(int d=0;d<4;d++)
                    {
                        int nx = node.first + dx[d];
                        int ny = node.second + dy[d];
                        if(nx<0||ny<0||nx>=N||ny>=M||visited[nx][ny]) continue;
                        if(north[nx][ny]!=0)
                        {
                            q.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    return num;         
}
void Melt()
{
    for (int i = 0; i < N; i++)
     fill(temp[i].begin(), temp[i].end(), 0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(north[i][j]>0)
            {
                int cnt = 0;
                for(int k=0;k<4;k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx<0||ny<0||nx>=N||ny>=M) continue;
                    if(north[nx][ny]==0) cnt++;
                }
                temp[i][j] = max(0, north[i][j]-cnt);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int answer = 0;
    
    cin>>N>>M;
    north.resize(N, vector<int>(M,0));
    temp.resize(N, vector<int>(M,0));
    visited.resize(N, vector<bool>(M,false));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>north[i][j];
        }
    }
    
    while(true)
    {
        answer++;
        Melt();
        north = temp;
        int num = BFS();
        if(num>=2)
        {
            cout<<answer;
            break;
        }
        else if(num == 0)
        {
            cout<<0;
            break;
        }
    }
    
}