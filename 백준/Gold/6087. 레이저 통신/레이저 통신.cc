using namespace std;

#include <iostream>
#include <vector>
#include <queue>

int W, H;
vector<vector<char>> map;
bool visited[101][101][4] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1 ,0, 0};
vector<pair<int, int>> cpos;
struct Node
{
    int x, y, dir;
    int mirrorCount;
    
    bool operator<(const Node& other) const
    {
        return mirrorCount > other.mirrorCount;    
    }
    Node(int a, int b, int d, int mirror): x(a), y(b), dir(d), mirrorCount(mirror) {}
};

void BFS(int a, int b)
{
    priority_queue<Node> pq;
    pq.push(Node(a,b,0,0));
    pq.push(Node(a,b,1,0));
    pq.push(Node(a,b,2,0));
    pq.push(Node(a,b,3,0));
    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        if(node.x==cpos[1].first && node.y==cpos[1].second)
        {
            cout<<node.mirrorCount;
            return;
        }
        visited[node.x][node.y][node.dir] = true;
        for(int i=0;i<4;i++)
        {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if(nx >=H || ny>=W || nx<0 || ny<0) continue;
            if(visited[nx][ny][i]|| map[nx][ny]=='*') continue;
            int nextMirror = (node.dir==i)?node.mirrorCount:node.mirrorCount+1;
            pq.push(Node(nx,ny,i,nextMirror));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>W>>H;
    map.resize(H, vector<char>(W));
    int cx, cy;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='C')
            {
                cpos.push_back({i, j});
            }
        }
        
    }
    BFS(cpos[0].first, cpos[0].second);
    return 0;
}