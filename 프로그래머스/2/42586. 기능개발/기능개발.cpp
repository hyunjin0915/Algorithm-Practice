#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for(int i = 0; i<progresses.size(); i++)
    {
        int day = (100 - progresses[i] )/ speeds[i];
        if((100 - progresses[i] ) % speeds[i] != 0) day+= 1;
        q.push(day);
    }
    while(!q.empty())
    {
        int max = q.front();
        q.pop();
        int cnt = 1;
        while(!q.empty())
        {
            int nd = q.front();
            if(nd <= max)
            {
                q.pop();
                cnt++;
            }
            else
            {
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}