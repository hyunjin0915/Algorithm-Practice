#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<vector<int>> vec;
int one = 0;
int zero = 0;

void check(int x, int y, int size)
{
    bool cut = false;
    int firstNum = vec[x][y];
    for(int i=x;i<x+size;i++)
    {
        for(int j=y;j<y+size;j++)
        {
            if(firstNum != vec[i][j])
            {
                cut = true;
                break;
            }
        }
    }
    if(cut)
    {
        check(x, y, size/2);
        check(x, y + size / 2, size / 2);
		check(x + size / 2, y, size / 2);
		check(x + size / 2, y + size / 2, size / 2);
    }
    else
    {
        if(firstNum == 1) one++;
        else zero++;
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    vec = arr;
    
    check(0, 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}