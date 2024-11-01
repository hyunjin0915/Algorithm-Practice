#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>, greater<int>> q;
    for(auto a : scoville)
    {
        q.push(a);
    }
    while(q.top()<K)
    {
        if(q.size()==1) return -1;
        int num1 = q.top();
        q.pop();
        int num2 = q.top();
        q.pop();
        q.push(num1 + num2*2);
        answer++;
    }
    return answer;
}