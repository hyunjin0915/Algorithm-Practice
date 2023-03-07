#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int index = section[0];
    int  s = 0;
    while(index<section.back())
    {
        if(index+m-1 < section.back())
        {
            answer++;
        }
        index = index+m; 
        if(index >= section.back())
            break;
        while(section[s]<index)
        {
            s++;
        }
       index = section[s];
    }
    return answer;
}