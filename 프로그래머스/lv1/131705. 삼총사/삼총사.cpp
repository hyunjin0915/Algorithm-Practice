#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    vector<bool> temp;

    for(int i=0;i<number.size()-3;i++)
        temp.push_back(0);
    for(int i = 0;i<3;i++)
        temp.push_back(1);
    
    do
    {
        int sum = 0;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==1)
                sum+=number[i];
        }
        if(sum==0) answer++;
    }while(next_permutation(temp.begin(),temp.end()));
    return answer;
}