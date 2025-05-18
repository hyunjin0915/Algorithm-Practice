#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wantMap;
    for(int i=0;i<want.size();i++)
    {
        wantMap[want[i]] = number[i];
    }
    for(int i=0;i<=discount.size()-10;i++)
    {
        map<string, int> temp(wantMap);
        bool able = true;
        for(int j=i;j<i+10;j++)
        {
            temp[discount[j]]--;
        }
        for(auto a : temp)
        {
            if(a.second > 0)
            {
                able = false;
                break;
            }
        }
        if(able) answer++;
    }
    return answer;
}