#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack <int> s;
    int size = numbers.size();
    answer.resize(size, 0);
    answer[size-1] = -1;
    s.push(numbers[size-1]);

    
    for(int i = size-2 ; i>=0 ;i--)
    {
        bool isSuccess = false;
        while(!s.empty())
        {
            if(s.top()>numbers[i])
            {
                answer[i] = s.top();
                isSuccess = true;
                break;
            }
            s.pop();
        }
        if(!isSuccess)
        {
            answer[i]=-1;
        }
        s.push(numbers[i]);
    }
    return answer;
}