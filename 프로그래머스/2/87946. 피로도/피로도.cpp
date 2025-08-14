#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> dgs;
vector<vector<int>> path;
vector<vector<vector<int>>> paths;
vector<bool> visited;

void DFS()
{
    if(path.size() == dgs.size()) 
    {
        paths.push_back(path);
        return;
    }
    for(int i=0;i<dgs.size();i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            path.push_back(dgs[i]);
            DFS();
            visited[i]=false;
            path.pop_back();
            
        }
    }
}

int GOGO(int k, vector<vector<int>> path)
{
    int cnt = 0;
    for(auto p : path)
    {
        if(k>=p[0])
        {
            k -= p[1];
            cnt++;
        }
    }
    return cnt;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    dgs = dungeons;
    visited.resize(dgs.size(), false);
    DFS();
    
    for(auto a : paths)
    {
        answer = max(answer, GOGO(k, a));
    }
    
    return answer;
}