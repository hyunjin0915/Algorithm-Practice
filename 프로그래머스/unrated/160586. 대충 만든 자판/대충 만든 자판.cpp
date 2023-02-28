#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    int min = 0;
    for(int i=0;i<keymap.size();i++)
    {
        for(int j=0;j<keymap[i].size();j++)
        {
            auto iter = m.find(keymap[i][j]);
            if(iter!=m.end())
            {
                if(iter->second<j+1) continue;
                else
                    m[keymap[i][j]] = j+1;
            }
            else
                m[keymap[i][j]] = j+1;
        }
    }
    for(int i=0;i<targets.size();i++)
    {
        int cnt = 0;
        for(int j=0;j<targets[i].size();j++)
        {
            if(m.find(targets[i][j])==m.end())
            {
                cnt = -1;
                break;
            }
            cnt += m[targets[i][j]];
        }
        answer.push_back(cnt);
    }
    for(auto it : m)
        cout<< it.first <<":"<<it.second<<"/";
    return answer;
}