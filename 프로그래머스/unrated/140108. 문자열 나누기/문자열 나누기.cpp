#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int a=1;
    int b=0;
    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];
        while(a!=b)
        {
            if(ch==s[i+1]) a++;
            else b++;
            i+=1;
        }
        answer++;
        a=1;
        b=0;
    }
    return answer;
}