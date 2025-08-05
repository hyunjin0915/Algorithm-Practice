#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    for(int num : nums)
    {
        s.insert(num);
    }
    int want = nums.size()/2;
    if(want > s.size()) return s.size();
    else return want;
    
}