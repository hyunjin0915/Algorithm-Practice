#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int num = 1;
    int i=0;
    stack<int> s;
    for(int i=0;i<order.size();i++)
    {
        if(order[i]>num)
        {
            while(order[i]!=num)
            {
                s.push(num);
                num++;
            }
            answer++;
            num++;
        }
        else if(order[i]<num)
        {
            if(s.top()==order[i])
            {
                answer++;
                s.pop();
            }
            else break;
        }
        else
        {
            answer++;
            num++;
        }
    }
   
    
    return answer;
}