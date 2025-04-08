#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    sort(works.begin(), works.end());
    for(int i=0;i<works.size();i++)
    {
        pq.push(works[i]);
    }
    while(n--)
    {
        int top = pq.top();
        if(top>0) top--;
        pq.pop();
        pq.push(top);
    }
    while(!pq.empty())
    {
        int top = pq.top();
        answer += (top*top);
        pq.pop();
    }
    return answer;
}