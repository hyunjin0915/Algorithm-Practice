using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long answer = 0;
    int N, C;
    cin>>N>>C;
    vector<long long> vec;
    long long num;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    
    long long minValue = 1;
    long long maxValue = vec[N-1] - vec[0];
    long long midValue;
    long long index = vec[0];
    while(minValue<=maxValue)
    {
        int cnt = 1;
        index = vec[0];
        midValue = (minValue + maxValue)/2;
        for(int i=1; i<N;i++)
        {
            if(vec[i] - index >= midValue)
            {
                cnt++;
                index = vec[i];
            }
        }
        if(cnt >= C)
        {
            answer = max(answer, midValue);
            minValue = midValue+1;
        }
        else
        {
            maxValue = midValue -1;
        }
    }
    cout<<answer;
    return 0;
}