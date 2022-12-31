#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    vector<int> data;
    for(int i=0;i<10;i++)
    {
        data.push_back(i);
    }
    for(int i=0;i<numbers.size();i++)
    {
        for(vector<int>::iterator it = data.begin();it!=data.end();)
        {
            if(numbers[i]==*it)
            {
                data.erase(it);
            }
            else
            {
                it++;
            }
        }
        
    }
     int answer = 0;
    for(vector<int>::iterator it = data.begin();it!=data.end();it++)
    {
        answer = answer + (*it);
    }
   
    return answer;
}