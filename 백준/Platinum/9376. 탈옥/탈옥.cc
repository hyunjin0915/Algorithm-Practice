using namespace std;
#include <iostream>
#include <queue>
#define INF 987654321

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

char map[105][105]={'.'};
vector<vector<int>> dist1;
vector<vector<int>> dist2;
vector<vector<int>> dist3;

int h, w;

vector<pair<int,int>> cPos;
int ans = INF;

void Add()
{
    for(int i=0;i<=h+1;i++)
    {
        for(int j=0;j<=w+1;j++)
        {
            if(map[i][j]=='*') continue;
            if (dist1[i][j] == -1 || dist2[i][j] == -1 || dist3[i][j] == -1) continue; // 도달 못한 경우
            int sum = dist1[i][j] +dist2[i][j]+dist3[i][j];
            if(map[i][j] == '#') sum-=2;
            ans = min(ans, sum);
        }
    }
}

void BFS(int x, int y,vector<vector<int>>& dist )
{
    int cnt = 0;
    deque<pair<int, int>> dq;
    dq.push_back({x,y});
    dist[x][y] = 0;
    while(!dq.empty())
    {
        auto cur = dq.front();
        dq.pop_front();
        for(int i=0;i<4;i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0||ny<0||nx>=h+2||ny>=w+2) continue;
            if(map[nx][ny] == '*' || dist[nx][ny]!=-1 )
            {
                continue;
            }
            if(map[nx][ny] == '#')
            {
                dist[nx][ny] = dist[cur.first][cur.second]+1;
                dq.push_back({nx,ny});
            }
            else
            {
                dist[nx][ny] = dist[cur.first][cur.second];
                dq.push_front({nx,ny});
            }
            
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int T;
 
    cin>>T;
    while(T--)
    {
        ans = INF;
        cPos.clear();
        cin>>h>>w;
        
        for (int i = 0; i < h+2; i++) 
        {
            for (int j = 0; j < w+2; j++) 
            {
                map[i][j] = '.';
            }
        }
    
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;
                map[i+1][j+1] = c;
                if (c == '$') {
                    cPos.push_back({i+1, j+1});
                    map[i+1][j+1] = '.';
                }
            }
        }

        dist1.assign(h+2, vector<int>(w+2, -1));
        dist2.assign(h+2, vector<int>(w+2, -1));
        dist3.assign(h+2, vector<int>(w+2, -1));
    
        
        BFS(0,0, dist1);
        auto pos = cPos[0];
        BFS(pos.first, pos.second, dist2);
        pos = cPos[1];
        BFS(pos.first, pos.second, dist3);
        
        Add();
        cout<<ans<<'\n';
    }
    
    return 0;
}