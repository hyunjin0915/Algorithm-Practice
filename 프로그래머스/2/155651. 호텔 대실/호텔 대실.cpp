#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(auto a:book_time)
    {
        int one, two;
        //one+=(a[0].substr(0,2) + a[0].substr(3,5));
        //two+=(a[1].substr(0,2) + a[1].substr(3,5));
        one = stoi(a[0].substr(0,2))*60+stoi(a[0].substr(3,5));
        two = stoi(a[1].substr(0,2))*60+stoi(a[1].substr(3,5))+10;
        v.push_back(make_pair(one, two));
    }
    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>,greater<int>> q;
    for(int i=0;i<v.size();i++)
    {
        if(!q.empty() && v[i].first>=q.top())
        {
            q.pop();
        }
        q.push(v[i].second);
    }
    return q.size();
}