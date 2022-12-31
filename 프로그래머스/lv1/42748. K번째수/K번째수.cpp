#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> tiger;
    vector<int> answer;
    for(int i=0;i<commands.size();i++)
    {
        for(int j=commands[i][0];j<=commands[i][1];j++)
        {
            tiger.push_back(array[j-1]);
            
        }
        
        sort(tiger.begin(),tiger.end());
        //int pick = commands[i][2];
        answer.push_back(tiger[commands[i][2]-1]);
        tiger.clear();
    }
    
    return answer;
}