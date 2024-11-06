#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i= left; i<= right;i++)
    {
        int num = ceil(sqrt(i));
        if(i == pow(num,2))
        {
            cout<<i<<',';
            answer -= i;
        }
        else
           answer += i;
    }

    return answer;
}