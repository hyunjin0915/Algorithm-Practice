#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> vX;
    vector<int> vY;
    
    
    for(int i=0;i<wallpaper.size();i++)
    {
        bool isChanged = false;
        for(int j=0;j<wallpaper[i].size();j++)
        {
            if(wallpaper[i][j]=='#')
            {
                vX.push_back(j);
                isChanged = true;
            }
            else
                continue;
        }
        if(isChanged)
            vY.push_back(i);
    }

    answer.push_back(*min_element(vY.begin(),vY.end()));
    answer.push_back(*min_element(vX.begin(),vX.end()));
    answer.push_back(*max_element(vY.begin(),vY.end())+1);
    answer.push_back(*max_element(vX.begin(),vX.end())+1);
   
    return answer;
}