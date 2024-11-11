#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> vec = arr;
    if(arr.size()==1){
        answer.push_back(-1);
        return answer;
    } 
    sort(vec.begin(), vec.end());
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==vec[0]) continue;
        else answer.push_back(arr[i]);
    }
    return answer;
}