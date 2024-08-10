#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(),B.end());
    int num = A.size();
    for(int i=0;i<num;i++)
    {
        answer += A[i]*B[num-i-1];
    }

    return answer;
}