#include <string>
#include <vector>
#include <queue>

using namespace std;

int s;
vector<vector<int>> v;

int BFS(int a, int b)
{
    vector<bool> visited(s+1, false);
    visited[a] = true;
    visited[b] = true;
    
    queue<int> q;
    
    q.push(a);
    int cnt = 1;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        
        for(int m: v[n])
        {
            if(!visited[m]) 
            {
                q.push(m);
                cnt++;
                visited[m]=true;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    s = n + 1;
    v.resize(n+1);
    for(int i=0;i<wires.size();i++)
    {
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i=0;i<wires.size();i++)
    {
        int cnt = BFS(wires[i][0], wires[i][1]);
        answer = min(answer, abs(cnt*2 - n));
    }
    return answer;
}