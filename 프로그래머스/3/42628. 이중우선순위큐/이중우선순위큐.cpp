#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    for(string str : operations)
    {
        char cmd = str[0];
        int num = stoi(str.substr(2));
        if(cmd == 'I')
        {
            ms.insert(num);
        }
        else if(cmd == 'D' && !ms.empty())
        {
            if(num == 1)
            {
                ms.erase(--ms.end());
            }
            else if(num == -1)
            {
                ms.erase(ms.begin());
            }
        }
    }
    if(ms.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    return answer;
}