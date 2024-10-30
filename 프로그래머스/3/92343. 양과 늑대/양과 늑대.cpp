#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vec;
vector<int> _info;
int answer = 0;

void DFS(int cur, int sheep, int wolf, queue<int>q)
{
    if(_info[cur] == 0) sheep++;
    else wolf ++;
    
    if(wolf >= sheep) return;
    
    answer = max(answer, sheep);
    
    for(int i=0;i<vec[cur].size();i++)
    {
        q.push(vec[cur][i]);
    }
    for(int i=0;i<q.size();i++)
    {
        int next = q.front();
        q.pop();
        DFS(next, sheep, wolf, q);
        q.push(next); //다시 돌아와서 재시도 가능!!
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    vec.resize(info.size());
    _info.assign(info.begin(), info.end()); //dfs에서 쓰려고 전역으로 변경 
    for(int i=0;i<edges.size();i++)
    {
        vec[edges[i][0]].push_back(edges[i][1]);
    }
    queue <int> q;
    DFS(0, 0, 0, q);
    
    return answer;
}