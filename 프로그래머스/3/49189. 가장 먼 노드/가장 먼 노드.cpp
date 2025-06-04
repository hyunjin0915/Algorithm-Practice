#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int cnt = 0;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> vec;
    vector<bool> visited;
    vec.resize(20001);
    visited.resize(20001, false);
    
    map<int, int> cnt;
    
    for(int i=0;i<edge.size();i++)
    {
        vec[edge[i][0]].push_back(edge[i][1]);
        vec[edge[i][1]].push_back(edge[i][0]);
        
    }
    
    queue<pair<int,int>> q;
    q.push({1, 0});
    visited[1] = true;
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        
        for(int i : vec[front.first])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push({i, front.second+1});
                cnt[front.second + 1] ++;                
            }
        }

    }

    return cnt.rbegin()->second;
}



