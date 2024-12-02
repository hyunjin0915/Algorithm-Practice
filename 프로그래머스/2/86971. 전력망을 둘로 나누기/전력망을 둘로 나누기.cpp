#include <string>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

vector<vector<int>> A;
int cnt;

void bfs(int x, int y)
{
    queue<int> q;
    vector<bool> visited(MAX);
    visited[x] = true;
    visited[y] = true;
    q.push(x);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(auto a:A[now])
        {
            if(visited[a]) continue;
            q.push(a);
            cnt++;
            visited[a] = true;
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n; 
    
    A.resize(n+1);
    for(auto a:wires)
    {
        A[a[0]].push_back(a[1]);
        A[a[1]].push_back(a[0]);
    }
    for(auto wire : wires)
    {
        cnt = 1;
        bfs(wire[0],wire[1]);
        answer = min(answer, abs(cnt*2-n));
    }
    return answer;
}