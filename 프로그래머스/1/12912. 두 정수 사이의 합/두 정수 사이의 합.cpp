#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int m , n;
    if(a<b)
    {
        m = b;
        n = a;
    }
    else if(a>b)
    {
        m = a;
        n = b;
    }
    else return a;
    
    for(int i = n ;i<=m;i++)
    {
        answer += i;
    }
    return answer;
}