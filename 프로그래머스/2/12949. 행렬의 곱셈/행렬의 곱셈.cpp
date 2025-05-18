#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int x1= arr1.size();
    int x2 = arr1[0].size();
    int y1= arr2.size();
    int y2 = arr2[0].size();
    
    answer.resize(x1);
    
    for(int i=0;i<x1;i++)
    {
        for(int k = 0; k<y2 ; k++)
        {
            int temp = 0;
            for(int j=0;j<y1;j++)
            {
                
                temp += arr1[i][j] * arr2[j][k];
            }
        answer[i].push_back(temp);
        }
        
    }
    
    return answer;
}