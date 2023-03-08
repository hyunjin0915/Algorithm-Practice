#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int index = section[0];
    for( int i=0;i<section.size();i++)
    {
        if(section[i]<index+m)
            continue;
        else
        {
            answer++;
            index = section[i];
        }
            
    }
    return answer;
}