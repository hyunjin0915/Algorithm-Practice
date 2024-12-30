#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    for(auto a:nums)
    {
        s.insert(a);
    }
    int cnt = nums.size()/2;
    if(s.size()>=cnt) return cnt;
    else return s.size();

}