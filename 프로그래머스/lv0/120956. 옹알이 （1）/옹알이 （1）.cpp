#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> v={"aya","ye","woo","ma"};
    
    for(int i=0;i<babbling.size();i++)
    {
           for(int j=0;j<v.size();j++)
           {
               if(babbling[i].find(v[j])!=string::npos)
               {
                   babbling[i].replace(babbling[i].find(v[j]),v[j].size(),"x");
               }
           }
        babbling[i].erase(remove(babbling[i].begin(),babbling[i].end(),'x'),babbling[i].end());
        if(babbling[i].size()==0) answer++;
    }
    
    return answer;
}