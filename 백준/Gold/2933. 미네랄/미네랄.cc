using namespace std;
#include <iostream>
#include<vector>
#include <queue>
#include <algorithm>

vector<vector<char>> cave;
vector<vector<bool>> visited;
int R, C;
int N;
bool isLeft = true;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


void Throw(int height)
{
    if(isLeft)
    {
        for(int i=0;i<C;i++)
        {
            if(cave[R-height][i] == 'x')
            {
                cave[R-height][i] = '.';
                break;
            }
        }
    }
    else
    {
        for(int i=C-1;i>=0;i--)
        {
            if(cave[R-height][i] == 'x')
            {
                cave[R-height][i] = '.';
                break;
            }
        }
    }
}

void BFS()
{
    visited.assign(R, vector<bool>(C, false));
    queue<pair<int, int>> q;
    for(int i=0;i<C;i++)
    {
        if(cave[R-1][i] == 'x')
        {
            visited[R-1][i] = true;
            q.push({R-1,i});
        }
    }
   
    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];
            if(nx>=R || ny>=C || nx<0 || ny<0 
                || visited[nx][ny]||cave[nx][ny]!='x') continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C;
    cave.resize(R, vector<char>(C,'.'));
    visited.resize(R, vector<bool>(C,false));
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            char c;
            cin >> c;
            cave[i][j] = c;
        }
    }
    cin>>N;
    
    while(N--)
    {
        int t;
        cin>>t;
        Throw(t);
        isLeft=!isLeft; //차례 바꾸기 
        
        BFS();
        
        vector<pair<int,int>> cluster;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(cave[i][j]=='x' && !visited[i][j])
                {
                    cluster.push_back({i,j});
                }
            }
        }
        
        if(cluster.empty()) continue;
        
        for (auto [r,c] : cluster) 
        {
            cave[r][c] = '.';
        }
        
        int drop = R;
        for(auto a : cluster)
        {
            int r = a.first + 1;
            int d = 0;
            while(r < R && cave[r][a.second]=='.')
            {
                d++; r++;
            }
            drop = min(d, drop);
        }
        
        for (auto [r,c] : cluster) 
        {
            cave[r + drop][c] = 'x';
        }
        
        
    }
    
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<cave[i][j];
        }
        cout<<'\n';
        
    }
    
    
}