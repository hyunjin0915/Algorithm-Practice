#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int num;
    for(int i=0;i<arr.size();i++)
    {
        
        if(i==0){
            answer.push_back(arr[i]);
            num = arr[i];
            continue;
        }
        if(num == arr[i]) continue;
        else
        {
            answer.push_back(arr[i]);
            num = arr[i];
        }
    }

    return answer;
}