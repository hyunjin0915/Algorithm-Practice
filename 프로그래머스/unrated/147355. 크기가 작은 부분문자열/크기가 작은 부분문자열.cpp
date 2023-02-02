#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0;i<=t.size()-p.size();i++)
    {
        if( stoll( t.substr(i, p.size()) ) <= stoll(p) ) answer++;
        //cout<<stoi(t.substr(i,p.size()))<<" ";
    }
    return answer;
}