#include <string>
#include <vector>
#include <queue>
//#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int w = 0;
    int i = 0;
    while(true)
    {
        if(i == (truck_weights.size()))break;
        if(q.size()<bridge_length)
        {
            if(w+truck_weights[i]<=weight)
            {
                q.push(truck_weights[i]);
                w += truck_weights[i];
                i++;
            }
            else
                q.push(0);
            
        }
        if(q.size()==bridge_length)
        {
            w-=(q.front());
            q.pop();
        }
        //cout<<q.front()<<',';
        answer++;
        
    }
    return answer+bridge_length;
}