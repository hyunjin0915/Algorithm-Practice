#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int w, h;
    int sum = (brown + 4) /2;
    for(int i = 3; i<=sum/2; i++)
    {
        int w = sum - i;
        int h = i;
        
        if((w-2) * (h-2) == yellow)
        {
            answer.push_back(w);
            answer.push_back(h);
            return answer;
        }
    }
    
    return answer;
}