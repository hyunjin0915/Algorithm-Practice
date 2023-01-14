#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    for(auto iter:nums)
        s.insert(iter);
    answer=s.size()>nums.size()/2?nums.size()/2:s.size();
    return answer;
}