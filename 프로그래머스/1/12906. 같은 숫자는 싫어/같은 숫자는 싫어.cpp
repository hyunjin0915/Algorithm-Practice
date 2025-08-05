#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;

    for(int n : arr)
    {
        if(!s.empty())
        {
            int num = s.top();
            if(num == n) continue;            
        }
        s.push(n);
    }
    answer.resize(s.size());
    for(int i = answer.size()-1;i>=0;i--)
    {
        answer[i] = s.top();
        s.pop();
    }

    return answer;
}