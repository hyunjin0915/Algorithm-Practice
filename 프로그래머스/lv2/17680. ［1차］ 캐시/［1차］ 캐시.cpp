#include <string>
#include <vector>
#include <list>
#include <algorithm>


using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> l;
    
    if(cacheSize==0) return cities.size()*5;
    for(int i=0;i<cities.size();i++)
    {
        for(char& ch:cities[i]) {ch = tolower(ch);}
        auto iter = find(l.begin(),l.end(),cities[i]);
        if(iter!=l.end()) //있으면
        {
            l.erase(iter);
            l.push_back(cities[i]);
            answer++;
            continue;
        }
        else //없으면
        {
            if(l.empty()||l.size()<cacheSize)
            {
                l.push_back(cities[i]);
                answer+=5;
                continue;
            }
            l.pop_front();
            l.push_back(cities[i]);
            answer+=5;
            continue;
        }
    }
    return answer;
}