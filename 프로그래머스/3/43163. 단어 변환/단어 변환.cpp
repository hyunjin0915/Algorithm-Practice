#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isNear(string a, string b);
void dfs(string begin, string target, vector<string> words, int step);
int answer = 50;
bool visited[50];

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if(answer == 50) return 0;

    return answer;
}

void dfs(string begin, string target, vector<string> words, int step)
{
    if(answer<=step) return;
    if(begin == target)
    {
        answer = min(answer, step);
        return;
    }
    for(int i=0;i<words.size();i++)
    {
        if(isNear(begin, words[i])&& !visited[i])
        {
            visited[i]=true;
            dfs(words[i], target, words, step+1);
            visited[i]=false;
        }
    }
    
}
bool isNear(string a, string b)
{
    int cnt = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            cnt++;
        if(cnt>1) return false;
    }
    return true;
}