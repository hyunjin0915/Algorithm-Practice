#include <string>
#include <vector>

using namespace std;

vector<int> v;

int fibo(int num)
{
    if(num<=1) return num;
    else if(v[num]!=0) return v[num];
    else
    {
        return v[num] = (fibo(num-1) + fibo(num-2))%1234567;
    }
}

int solution(int n) {
    int answer = 0;
    v.resize(100001,0);
    v[0]=0;
    v[1]=1;
    fibo(n);
    answer = v[n];
    return (answer);
}
