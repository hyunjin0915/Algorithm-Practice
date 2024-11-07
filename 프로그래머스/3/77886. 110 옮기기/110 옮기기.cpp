#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(auto str : s)
    {
        int oneCnt = 0;
        int cnt = 0;
        string ans = "";
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='1')
            {
                oneCnt++;
            }
            else
            {
                if(oneCnt >= 2) //110이면
                {
                    cnt ++;
                    oneCnt -=2;
                }
                else
                {
                    for(int j = 0;j<oneCnt;j++)
                    {
                        ans += '1';
                    }
                    ans +='0';
                    oneCnt = 0;
                }
            }
        }
        for(int j=0;j<cnt;j++)
        {
            ans += '1';
            ans += '1';
            ans += '0';
        }
        for(int j=0;j<oneCnt;j++)
        {
            ans +='1';
        }
        answer.push_back(ans);
    }
    return answer;
}