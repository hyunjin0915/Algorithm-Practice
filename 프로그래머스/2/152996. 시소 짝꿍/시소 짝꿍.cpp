#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long long, long long> m;
    for(auto a : weights)
    {
        m[a]++;
    }
    for(auto a : m)
    {
        long long w = a.first;
        long long c = a.second;
        
        if(c>1)
        {
            answer += c*(c-1)/2;
        }
        if(w*3%2==0)
        {
            if(m.find(w*3/2)!=m.end())
                answer+=c*m[w*3/2];
        }
        if(w*3%4==0)
        {
            if(m.find(w*3/4)!=m.end())
                answer+=c*m[w*3/4];
        }
        if(w*2%4==0)
        {
            if(m.find(w*2/4)!=m.end())
                answer+=c*m[w*2/4];
        }
    }
    return answer;
}