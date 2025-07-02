using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>


int M, N, H;
int dx[6] = {0, 0, -1, 1,0,0};
int dy[6] = {1, -1, 0, 0,0,0};
int dz[6] = {0, 0, 0, 0,1, -1};

vector<vector<vector<int>>> map;
vector<vector<vector<bool>>> visited;
int cnt = 0;
int tomato = 0;
int days = 0;
queue<tuple<int, int, int>> q;

void BFS()
{
    while(!q.empty())
    {
        int sz = q.size();
        bool turned = false;
        for(int i=0;i<sz;i++)
        {
            auto [z,y,x]= q.front();
            q.pop();
            visited[z][y][x] = true;
            // int up = get<0>(node) - 1;
            // int down = get<0>(node) + 1;
            /*if(up>=0) //윗층 존재하면 체크
            {
                if(map[up][get<1>(node)][get<2>(node)]!=-1 && !visited[up][get<1>(node)][get<2>(node)])
                {
                    map[up][get<1>(node)][get<2>(node)] = 1;
                    cnt++;
                    q.push({up,get<1>(node),get<2>(node)});
                }
            }
            if(down>=0 && down<H)
            {
                if(map[down][get<1>(node)][get<2>(node)]!=-1 && !visited[down][get<1>(node)][get<2>(node)])
                {
                    map[down][get<1>(node)][get<2>(node)] = 1;
                    cnt++;
                    q.push({down,get<1>(node),get<2>(node)});
                }
            }*/
            for(int l = 0;l<6;l++)
            {
                int nz = dz[l] + z;
                int nx = dx[l] + x;
                int ny = dy[l] + y;
                if(nz<0 ||nx<0 || ny<0 || nz>=H|| nx>=M || ny>= N) continue;
                if(map[nz][ny][nx] !=0 || visited[nz][ny][nx]) continue;
                map[nz][ny][nx]=1;
                cnt++;
                q.push({nz,ny,nx});
                turned = true;
            }
            
        }
        
        if(turned) days++;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>M>>N>>H;
    map.resize(H, vector<vector<int>>(N, vector<int>(M)));
    visited.resize(H, vector<vector<bool>>(N, vector<bool>(M, false)));
    
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                cin>>map[i][j][k];
                if(map[i][j][k] == 0) tomato++;
                if(map[i][j][k] == 1) q.push({i,j,k});
            }
        }
    }
    BFS();
    
    if(cnt == tomato) cout<<days;
    else cout<<-1;
    return 0;
}