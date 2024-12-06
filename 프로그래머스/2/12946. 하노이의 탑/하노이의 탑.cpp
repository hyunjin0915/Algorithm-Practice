#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int start, int end, int temp)
{
    if(n==1)
    {
        vector<int> vec;
        vec.push_back(start);
        vec.push_back(end);
        answer.push_back(vec);
    }
    else
    {
        hanoi(n-1, start, temp, end);
        vector<int> vec;
        vec.push_back(start);
        vec.push_back(end);
        answer.push_back(vec);
        hanoi(n-1, temp, end, start);
    }
}

vector<vector<int>> solution(int n) {
    
    hanoi(n, 1, 3, 2);
    return answer;
}