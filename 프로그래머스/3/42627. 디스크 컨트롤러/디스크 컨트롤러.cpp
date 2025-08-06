#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if(a.second != b.second)
        {
            return a.second > b.second;
        }
        if(a.first!= b.first)
        {
            return a.first > b.first;
        }
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    vector<int> ans;
    sort(jobs.begin(), jobs.end()
        , [](auto &a, auto &b){ return a[0] < b[0]; });
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp > pq;
    
    int index = 0;
    int time = 0;
    
    while(index < jobs.size() || !pq.empty())
    {
        if(pq.empty() && time < jobs[index][0])
        {
            time = jobs[index][0];
        }
        
        while(index < jobs.size() &&jobs[index][0] <= time)
        {
            pq.push({jobs[index][0], jobs[index][1]});
            index++;
        }
        
        auto[call, cost] = pq.top();
        pq.pop();
        time += cost;
        int wait = (time) - call;
        ans.push_back(wait);
    }
    
    int sum = accumulate(ans.begin(), ans.end(), 0);
    return sum / ans.size();
    
}