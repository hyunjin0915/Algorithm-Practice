#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char c;
    set<string> s;

    for(int i=0;i<words.size();i++)
    {
        string temp = words[i];
        if(i==0)
        {
            c = temp[temp.size()-1];
            s.insert(temp);
            continue;
        }
        if(temp[0]!=c || s.find(temp)!=s.end())
        {
            int num = (i+1)%n!=0 ? (i+1)%n : n;
            answer.push_back(num);
            num = (i+1)%n==0 ? (i+1)/n : (i+1)/n+1;
            answer.push_back(num);
            return answer;
        }
        else
        {
            c = temp[temp.size()-1];
            s.insert(temp);
            continue;
        }
        
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}