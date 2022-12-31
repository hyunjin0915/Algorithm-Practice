#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a && n>=2)
    {
        answer += (n/a)*b;
        n=((n/a)*b)+(n%a); //남은 수
    }
    return answer;
}