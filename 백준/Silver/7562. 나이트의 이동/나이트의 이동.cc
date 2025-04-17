using namespace std;
#include <iostream>
#include <queue>
#include <string.h>

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int visited[301][301] = {false,};
int arr[301][301] = {0, };

int T, I, a,b,c,d;
void BFS(int x, int y);


int main()
{
    cin>>T;
    
    while(T--)
    {
       cin>>I>>a>>b>>c>>d; 
       
       BFS(a,b);
       cout<<arr[c][d]<<'\n';
       memset(visited, false, sizeof(visited));
       memset(arr, 0, sizeof(arr));
    }

    return 0;
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx<0 || nx>=I || ny<0 || ny >=I) continue;
            if(!visited[nx][ny])
            {
                arr[nx][ny] = arr[xx][yy] + 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}