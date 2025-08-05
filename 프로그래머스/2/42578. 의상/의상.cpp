#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for(auto cloth : clothes)
    {
        if(m.find(cloth[1])!=m.end())   m[cloth[1]] ++;
        else m[cloth[1]] = 1;
    }

    for(auto x : m)
    {
        answer *= (x.second+1);
    }
    
        return answer - 1;
   
}