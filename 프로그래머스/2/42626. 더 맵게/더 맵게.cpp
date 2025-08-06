#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int s : scoville)
    {
        pq.push(s);
    }
    
    while(pq.top()<K)
    {
        if(pq.size()==1) return -1;
        answer++;
        
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        
        int sum = n1 + n2 * 2;
        pq.push(sum);
    }
    
    return answer;
}