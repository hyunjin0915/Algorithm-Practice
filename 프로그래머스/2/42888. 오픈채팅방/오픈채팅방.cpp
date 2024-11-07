#include <string>
#include <vector>
#include<sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> name;
    
    vector<pair<string, string>> info;
    for(auto a : record)
    {
        stringstream ss(a);
        vector<string> words;
        string word;
        while(ss >> word)
        {
            words.push_back(word);
        }
        if(words[0]=="Enter" || words[0]=="Change")
        {
            name[words[1]]=words[2];
        }
        info.push_back(make_pair(words[0], words[1]));
    }
    for(int i=0;i<info.size();i++)
    {
        string ans = "";
        ans += name[info[i].second];
        ans += "님이 ";
        if(info[i].first == "Enter")
        {
            ans += "들어왔습니다.";
        }
        else if(info[i].first == "Leave")
        {
            ans += "나갔습니다.";
        }
        else continue;
        answer.push_back(ans);
    }
    return answer;
}