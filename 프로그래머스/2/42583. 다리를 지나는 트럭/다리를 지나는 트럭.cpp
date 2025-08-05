#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curW = 0;
    int i = 0;
    deque<int> dq;
    //모든 트럭이 건너는데 정해진 무게를 넘기면 안됨
    while(true)
    {
        if(i == truck_weights.size()) break;
        if(dq.size()<bridge_length)
        {
            if((curW + truck_weights[i]) <= weight)
            {
                dq.push_back(truck_weights[i]);
                curW += truck_weights[i];
                i++;
            }
            else
            {
                dq.push_back(0);
            }
        }
        if(dq.size() == bridge_length)
        {
            curW -= dq.front();
            dq.pop_front();
        }
        answer++;
    }
    
    return answer + bridge_length;
}