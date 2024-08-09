#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string str="";
    
    vector<int> v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ' ') 
        {
            v.push_back(stoi(str));
            str="";
        }
        else str += s[i];
    }
    v.push_back(stoi(str));
    sort(v.begin(), v.end());
    
    int n,m;
    n = v[0];
    m=v[v.size()-1];
    answer += to_string(n);
    answer +=' ';
    answer += to_string(m);

    
    return answer;
}