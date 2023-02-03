#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset <int> ms;
    for(int i=0;i<score.size();i++)
    {
        ms.insert(score[i]);
        if(ms.size()>k)
        {
            ms.erase(ms.begin());
            answer.push_back(*ms.begin());
        }
        else
            answer.push_back(*ms.begin());
    }
    return answer;
}