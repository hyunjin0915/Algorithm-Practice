using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    long long cnt = 1;
    long long num = 0;
    long long answer = 1;
    cin>>N;
    while(true)
    {
        if(cnt>=N) break;
        num += 6;
        cnt += num;
        answer++;
    }
    cout<<answer;
}