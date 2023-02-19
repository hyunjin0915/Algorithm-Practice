#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<brown;i++)
    {
        if((i/2-2)*((brown+4-i)/2-2)==yellow)
        {            
            answer.push_back((brown+4-i)/2);
            answer.push_back(i/2);
            return answer;
        }
    }
}