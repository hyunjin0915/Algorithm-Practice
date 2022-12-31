#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(long long i=0;i<=d;i+=k)
    {
        long long ld = static_cast<long long>(d);
        long long x = static_cast<long long>(sqrt(ld*ld-i*i));
        answer+=static_cast<long long>(x/k)+1;
    }
    return answer;
}