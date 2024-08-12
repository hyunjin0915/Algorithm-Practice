#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=1;i<n;i++)
    {
        int sum = 0; int t = i;
        while(sum<n)
        {
            sum+=t;
            t++;
        }
        if(sum==n)
        {
            answer++;
        }
    }
    return answer;
}