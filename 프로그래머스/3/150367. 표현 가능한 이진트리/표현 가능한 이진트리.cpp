#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPowerofTwo(int n)
{
    return n &&(!(n&(n-1)));
}
bool isAllZero(string str) {
    for (char c : str) {
        if (c != '0') return false;
    }
    return true;
}
bool canDraw(string str)
{
    if (str.length() == 1 || isAllZero(str)) return true;
 
    int midIdx = str.length() / 2;
    string left = str.substr(0, midIdx);
    string right = str.substr(midIdx + 1);
 
    if (str[midIdx] == '1' && canDraw(left) && canDraw(right)) return true;
    else return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size();i++)
    {
        int num;
        string binary = "";
        while(numbers[i]!=0)
        {
            binary+=to_string(numbers[i]%2);
            numbers[i]/=2;
        }
        
        while(!isPowerofTwo(binary.size()+1))
        {
            binary+='0';
        }
        reverse(binary.begin(), binary.end());
        
        answer.push_back(canDraw(binary));
    }
    return answer;
}