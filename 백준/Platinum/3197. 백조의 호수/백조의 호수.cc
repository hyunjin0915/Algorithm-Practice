using namespace std;
#include <iostream>
#include <vector>
#include <queue>

vector<vector<char>> arr;
vector<vector<bool>> visited;

vector<pair<int,int>> L;

int R,C;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> waterQ;      
queue<pair<int, int>> nextWaterQ;  

queue<pair<int,int>> swanQ, nextSwanQ;

void ICE()
{
    int sz = waterQ.size();
    while (sz--) {
        auto [x, y] = waterQ.front();
        waterQ.pop();
    
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
    
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (arr[nx][ny] == 'X') {
                arr[nx][ny] = '.'; // 얼음을 물로 녹임
                nextWaterQ.push({nx, ny});
            }
        }
    }
    
    waterQ = nextWaterQ;
    while (!nextWaterQ.empty()) nextWaterQ.pop();  // 초기화
    

    /*for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(arr[i][j] == 'X') continue;
            else
            {
                for(int i=0;i<4;i++)
                {
                    int nx = i + dx[i];
                    int ny = j + dy[i];
                    if(nx < 0 || ny<0 || nx>R|| ny>C) continue;
                    
                    if(arr[nx][ny] == 'X')
                    {
                        tempArr[nx][ny] = '.';
                    }
                    
                }
            }
        }
    }
    arr = tempArr;*/
}

bool BFS()
{
    while(!swanQ.empty())
    {
        auto front = swanQ.front();
        swanQ.pop();
        int tx = front.first;
        int ty = front.second;
        
        for(int i=0;i<4;i++)
        {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if(nx < 0 || ny<0 || nx>=R|| ny>=C || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if(arr[nx][ny]=='X') nextSwanQ.push({nx,ny});
            else if(arr[nx][ny]=='.' ) swanQ.push({nx,ny});
            else  if (nx == L[1].first && ny == L[1].second)return true;

        }
    }
    swanQ = nextSwanQ;
    while(!nextSwanQ.empty()) nextSwanQ.pop();
    return false;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int answer = 0;
    
    cin>>R>>C;
    arr.resize(R);
    visited.resize(R);
    char a;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>a;
            arr[i].push_back(a);
            visited[i].push_back(false);
            if(a=='L' || a=='.')
            {
                waterQ.push({i,j});
                
            }
            if(a=='L') 
            {
                L.push_back({i,j});
            }
        }
    }
    swanQ.push(L[0]);
    visited[L[0].first][L[0].second] = true;
    
    while(!BFS())
    {
        answer++;
        ICE();
    }
    cout<<answer;

}