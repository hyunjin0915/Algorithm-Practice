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
        if(sizes[i][0]<=sizes[i][1])
        {
            int tmp = sizes[i][0];
            sizes[i][0]=sizes[i][1];
            sizes[i][1]=tmp;
        }
        if(max1<=sizes[i][0]) max1=sizes[i][0];
        if(max2<=sizes[i][1]) max2=sizes[i][1];
    }
    return max1*max2;
}