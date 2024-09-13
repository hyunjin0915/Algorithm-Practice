#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(string s) {
    int length = s.size();
    int answer = 0;
    for(int i=0;i<length;i++)
    {
        stack<char> st;
        bool isOk = true;
        for(int j=i; j<i+length; j++)
        {
            int index = j>=length?j%length:j;
            if(s[index]=='('||s[index]=='['||s[index]=='{') st.push(s[index]);
            else
            {
                if(st.empty()) {isOk = false; break;}
                char temp = st.top();
                st.pop();
                if(s[index]==')' && temp == '(') continue;
                if(s[index]==']' && temp == '[') continue;
                if(s[index]=='}' && temp == '{') continue;
                else isOk = false;
            }
        }
        if(st.empty() && isOk) {answer++;}
    }
    return answer;
}