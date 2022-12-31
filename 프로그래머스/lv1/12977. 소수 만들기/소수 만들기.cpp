#include <vector>

using namespace std;

bool isPrime(int num)
{
    for(int i=2; i<num;i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0; 
    int num=0;
    
    for(int i = 0;i<nums.size()-2;i++)
    {
        for(int j=i+1;j<nums.size()-1;j++)
        {
            for(int z=j+1;z<nums.size();z++)
            {
                num = nums[i]+nums[j]+nums[z];
                if(isPrime(num)) answer++;
            }
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
   

    return answer;
}