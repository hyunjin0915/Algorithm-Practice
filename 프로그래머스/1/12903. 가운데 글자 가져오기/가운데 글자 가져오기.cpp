#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int length = s.size();
    if(length%2==0)
    {
        answer += s[length/2-1];
    }
    answer += s[length/2];
    return answer;
}