#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i=0;i<s.size();i++)
    {
        char c = s[i];
        int num = 0;
        while(num != index)
        {
            c++;
            num++;
            if(c>122) c-=26;
            if(skip.find(c)!=string::npos)
                num--;
        }
        s[i]=c;
    }
    
    return s;
}