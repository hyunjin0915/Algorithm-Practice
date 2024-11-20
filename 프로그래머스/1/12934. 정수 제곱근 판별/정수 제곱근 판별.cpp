#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long num = sqrt(n);
    if(pow(num,2)==n) return (pow(num+1,2));
    return -1;
}