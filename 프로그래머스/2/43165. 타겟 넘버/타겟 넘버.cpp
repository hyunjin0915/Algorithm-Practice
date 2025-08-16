#include <string>
#include <vector>

using namespace std;

int length, t;
int answer = 0;

vector<int> nums;

void DFS(int depth, int count)
{
    if(depth == length) 
    {
        if(count == t) 
        {
            answer++;
        }
        return;
    }
    
    DFS(depth+1, count + nums[depth]);
    DFS(depth+1, count - nums[depth]);
    
}

int solution(vector<int> numbers, int target) {
    length = numbers.size();
    t = target;
    nums = numbers;
    
    DFS(0, 0);
    
    return answer;
}