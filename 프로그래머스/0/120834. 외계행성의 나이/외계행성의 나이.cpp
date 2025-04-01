#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    string lang = "abcdefghij";
    string stAge = to_string(age);
    for(int i=0;i<stAge.size();i++)
    {
        answer += lang[stAge[i]-'0'];
    }
    return answer;
}