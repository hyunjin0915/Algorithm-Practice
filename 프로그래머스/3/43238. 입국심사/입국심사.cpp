#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = n * (long long)times.back();
    
    while(left <= right)
    {
        long long mid = (left + right)/2;
        long long num = 0;
        for(int i=0;i<times.size();i++)
        {
            num += mid/times[i];
        }
        if(num >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else left = mid + 1;
    }
    return answer;
}