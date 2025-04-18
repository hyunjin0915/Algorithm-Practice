using namespace std;
#include <iostream>
#include <queue>

int N, M;
int arr[1001][1001] = {0, };
queue<pair<int, int>> q;


int dx[4] = {0, 0, -1, 1};
int dy[4] = {1,-1,0,0};

int answer = 0;

void BFS();

int main()
{
    cin>>M>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)
            {
                q.push({i,j});
            }
        }
    }
    BFS();
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(arr[i][j]==0)
            {
                cout<<-1;
                return 0;
            }
            else answer = max(answer, arr[i][j]);
        }
    }
    cout<<answer-1;
    return 0;
}

void BFS()
{
    while(!q.empty())
    {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if(nx<0||nx>=N || ny<0||ny>=M) continue;
            
                if(arr[nx][ny]==0)
                {
                    q.push({nx,ny});
                    arr[nx][ny] = arr[fx][fy]+1;
                }
            
            
        }

    }

}