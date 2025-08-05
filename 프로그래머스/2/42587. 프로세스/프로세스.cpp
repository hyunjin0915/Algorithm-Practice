#include <string>
#include <vector>
#include <set>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> ans;
    ans.resize(priorities.size());
    
    deque<pair<int, int>> dq;
    multiset<int, greater<int>> ms;
    for(int i = 0;i<priorities.size();i++)
    {
        dq.push_back({priorities[i], i});
        ms.insert(priorities[i]);
    }
    int i = 1;
    while(!dq.empty())
    {
        int max = *ms.begin();
        
        while(dq.front().first < max)
        {
            auto[np, ni] = dq.front();
            dq.pop_front();
            dq.push_back({np, ni});
        }
        auto[a, b] = dq.front();
        dq.pop_front();
        ms.erase(ms.begin());
        ans[b] = i;
        i++;
    }
    return ans[location];
}