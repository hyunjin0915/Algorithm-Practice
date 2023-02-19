#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    multimap<int,int> m;
    for(int i=0;i<numbers.size();i++)
    {
        string num = to_string(numbers[i]);
        m.insert(make_pair(stoi((num+num+num+num).substr(0,4)),numbers[i]));
    }
    for(auto it = m.rbegin();it!=m.rend();it++)
    {
        answer+=to_string(it->second);
    }
    if(answer[0]=='0') return "0";
    return answer;
}