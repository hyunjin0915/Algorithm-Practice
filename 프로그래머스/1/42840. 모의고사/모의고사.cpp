#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correct(3, 0);
    
    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int indexOne=0;
    int indexTwo = 0;
    int indexThree = 0;
    
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    
    for(int a : answers)
    {
        if(a == one[indexOne]) correct[0]++;
        if(a == two[indexTwo]) correct[1]++;
        if(a == three[indexThree]) correct[2]++;
        
        indexOne = (indexOne+1) >= 5 ? 0 : indexOne+1;
        indexTwo = (indexTwo+1) >=8 ? 0 : indexTwo+1;
        indexThree = (indexThree+1) >= 10 ? 0 : indexThree+1;
    }
    int m = *max_element(correct.begin(), correct.end());
    for(int i = 0;i<correct.size();i++)
    {
        if(m == correct[i])
        {
            answer.push_back(i+1);
        }
    }
    return answer;
}