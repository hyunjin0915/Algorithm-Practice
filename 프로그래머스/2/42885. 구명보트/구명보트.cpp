#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i=0;
    int j = people.size()-1;
    
    sort(people.begin(),people.end(),greater<>());
    
    while(i<j)
    {
        if(people[i]+people[j]<=limit)
        {
            answer++;
            j--;
        }
        i++;
    }
    return people.size()- answer;
}