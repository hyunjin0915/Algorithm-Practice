#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i=0;i<s.size();i++)
    {
        if(i==0)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                s[i] -=32;
            }
            answer+=s[i];
            continue;
        }
        else if(s[i-1]==' ')
        {
            if(s[i]>='a' && s[i]<='z')
            {
                s[i] -=32;
                answer+=s[i];
                continue;
            }
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            s[i]+=32;
            answer += s[i];
            continue;
        }
        answer += s[i];
    }
    
    return answer;
}