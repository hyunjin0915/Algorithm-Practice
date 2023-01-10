#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    map<string,int>::iterator iter;
    for(int i=0;i<participant.size();i++)
    {
        iter =m.find(participant[i]);
        if(iter!=m.end())
        {
            iter->second+=1;
        }
        else
        {
            m.insert(make_pair(participant[i],1));
        }
    }
    for(int i=0;i<completion.size();i++)
    {
        iter =m.find(completion[i]);
        iter->second-=1;
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second > 0 )
            answer = it->first;
    }
    return answer;
}