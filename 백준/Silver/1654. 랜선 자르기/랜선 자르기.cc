using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int K,N;
    cin>>K>>N;
    
    vector<int> vec;
    double sum = 0;
    int num;
    for(int i=0;i<K;i++)
    {
        cin>>num;
        vec.push_back(num);
        sum += num;
    }
    //sort(vec.begin(), vec.end());
    
    long long maxValue = sum/N;
    long long minValue = 1;
    long long midValue;
    long long answer = 0;
    while(minValue<=maxValue)
    {
        midValue = (maxValue + minValue)/2;
        int cnt = 0;
        for(int i=0;i<vec.size();i++)
        {
            cnt += vec[i]/midValue;
        }
        if(cnt<N)
        {
            maxValue = midValue-1;
            continue;
        }
        else if(cnt>=N)
        {
            answer = max(answer, midValue);
            minValue = midValue+1;
            continue;
        }
    
    }
    cout<<answer;
}