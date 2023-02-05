#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int counting(int n)
{
    int cnt=0;
    if(n==1) return 1;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0) 
        {
            if(i==sqrt(n)) cnt-=1;
            cnt+=2;
            continue;
        }
    }
    return cnt;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> v;
    for(int i=1;i<=number;i++)
    {
        v.push_back(counting(i));
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>limit) answer+=power;
        else answer+=v[i];
    }
    return answer;
}