#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0;i<progresses.size();i++)
    {
        progresses[i] = (100 - progresses[i])/speeds[i];
        if((100 - progresses[i])%speeds[i] !=0) progresses[i]+=1;
    }
    int num = progresses[0];
    int cnt = 1;
    for(int i=1;i<progresses.size();i++)
    {
        if(progresses[i]<=num) cnt++;
        else
        {
            answer.push_back(cnt);
            cnt = 1;
            num = progresses[i];
        }
    }
    answer.push_back(cnt);
    return answer;
}