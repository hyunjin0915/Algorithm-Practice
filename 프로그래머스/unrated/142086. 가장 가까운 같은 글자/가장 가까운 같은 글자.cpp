#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    set<int> ss;
    for(int i=0;i<s.size();i++)
    {
        if(ss.find(s[i])==ss.end()) answer.push_back(-1);
        else
        {
            int min=0;
            for(int j=0;j<i;j++)
            {
                if(s[j]==s[i]) min=i-j;
            }
            answer.push_back(min);
        }
        ss.insert(s[i]);
    }
    return answer;
}