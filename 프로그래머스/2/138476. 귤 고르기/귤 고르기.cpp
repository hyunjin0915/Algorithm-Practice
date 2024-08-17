#include <string>
#include <vector>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>&a, pair<int, int>& b)
{
    return a.second > b.second;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int>m;
    for(auto &val : tangerine)
    {
        m[val]++;
    }
    vector<std::pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);
    int sum = 0;
    for(auto& val : v)
    {
        if(sum >= k) break;
        else
        {
            sum += val.second;
            answer++;
        }
    }
    return answer;
}