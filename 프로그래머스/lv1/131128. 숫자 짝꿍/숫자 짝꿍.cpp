#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int cntX[10] = {0};
    int cntY[10] = {0};
    for(auto i:X)
        cntX[(i-'0')]++;
    for(auto i:Y)
        cntY[(i-'0')]++;
    for(int i=9;i>=0;i--)
    {
        if(cntX[i]!=0 && cntY[i]!=0)
        {
            for(int j = min(cntX[i],cntY[i]);j>0;j--)
                answer+=i+'0';
        }
    }
    if(answer[0]=='0') answer="0";
    if(answer=="") answer="-1";
    return answer;
}