#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
map<string, vector<string>> maps;
map<string, vector<bool>> visited;
int T;

bool DFS(string cur, int cnt)
{
    if(cnt == T) return true;
    
    auto& path = maps[cur];
    auto& flags = visited[cur];
    
    for(int i=0;i<path.size();i++)
    {
        if(flags[i]) continue;
        flags[i] = true;
        answer.push_back(path[i]);
        if(DFS(path[i], cnt+1)) return true;
        flags[i] = false;
        answer.pop_back();
    }
    return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    
    T = tickets.size();
    for(auto t : tickets)
    {
        maps[t[0]].push_back(t[1]);
    }
    
    for(auto& t : maps)
    {
        auto& v = t.second;
        sort(v.begin(), v.end());
        visited[t.first] = vector<bool>(v.size(), false);
    }
    
    answer.push_back("ICN");
    DFS("ICN", 0);
    
    return answer;
}