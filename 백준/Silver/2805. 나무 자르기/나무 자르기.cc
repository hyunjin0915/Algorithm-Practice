using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    long long N,M;
    cin>>N>>M;
    
    vector<long long> vec;
    long long num;
    long long maxValue = 0;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        vec.push_back(num);
        maxValue = max(maxValue, num);
    }
    
    long long minValue = 0;
    long long midValue;
    long long answer = 0;
    while(minValue<=maxValue)
    {
        midValue = (maxValue + minValue)/2;
        long long cnt = 0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i] < midValue) continue;
            cnt += (vec[i] - midValue);
        }
        if(cnt<M)
        {
            maxValue = midValue-1;
            continue;
        }
        else if(cnt>=M)
        {
            answer = max(answer, midValue);
            minValue = midValue+1;
            continue;
        }
    
    }
    cout<<answer;
}