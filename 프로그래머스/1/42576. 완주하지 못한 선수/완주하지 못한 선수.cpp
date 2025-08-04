#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(string name : participant)
    {
        if(m.find(name)!=m.end())
        {
            m[name] ++;
        }
        else m[name] = 1;
    }
    for(string name : completion)
    {
        m[name]--;
    }
    for(auto a : m)
    {
        if(a.second != 0) return a.first;
    }
    return answer;
}