#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max1=0;
    int max2=0;
    
    for(int i=0;i<sizes.size();i++)
    {
        max1 = max(max1, max(sizes[i][0],sizes[i][1]));
        max2 = max(max2, min(sizes[i][0],sizes[i][1]));
    }
    return max1*max2;
}