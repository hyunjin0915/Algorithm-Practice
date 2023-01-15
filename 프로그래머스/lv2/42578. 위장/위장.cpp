#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> mm;
    
    for(int i=0;i<clothes.size();i++)
    {
        mm[clothes[i][1]]+=1;
    }
    for(auto iter:mm)
    {
        answer*=(iter.second+1);
    }
    return --answer;
}