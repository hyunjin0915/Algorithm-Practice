#include <string>
#include <vector>

using namespace std;

int cntOne(int n)
{
    int cnt = 0;
    while(n>0)
    {
        if(n%2==1) cnt++;
        n/=2;
    }
    return cnt;
}
int solution(int n) {
    int num = cntOne(n);
    
    while(true)
    {
        n+=1;
        if(num==cntOne(n)) break;
    }
    return n;
}