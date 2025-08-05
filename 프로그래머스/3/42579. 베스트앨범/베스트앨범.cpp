#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    else return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, vector<pair<int, int>>> mapping;
    
    for(int i = 0; i<genres.size();i++)
    {
        mapping[genres[i]].push_back({plays[i], i});
    }
    map<int, string, greater<int>> m;
    for(auto a : mapping)
    {
        int cnt = 0;
        for(auto x : a.second)
        {
            cnt += x.first;
        }
        m[cnt] = a.first;
        
    }
    
    for(auto g : m)
    {
        auto songs = mapping[g.second];
        sort(songs.begin(), songs.end(), comp);
        for(int i = 0 ; i<2;i++)
        {
            answer.push_back(songs[i].second);
            if(songs.size() == 1) break;
        }
    }
    return answer;
}