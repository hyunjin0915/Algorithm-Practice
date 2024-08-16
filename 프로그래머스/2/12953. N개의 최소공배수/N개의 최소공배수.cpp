#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
int solution(vector<int> arr) {
    int answer = 0;
    if(arr.size()==1) return arr[0];
    else if(arr.size()==2) return (arr[0]*arr[1])/gcd(arr[0],arr[1]);
    else
    {
        int num = (arr[0]*arr[1])/gcd(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++)
        {
            num = (num*arr[i])/gcd(num, arr[i]);
        }
        answer = num;
    }
    return answer;
}