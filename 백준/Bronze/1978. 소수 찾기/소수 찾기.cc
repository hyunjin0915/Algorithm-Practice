#include <iostream>
#include <cmath>
using namespace std;

bool isCheck(int num)
{
    if(num==1) return false;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}
int main()
{
    int N;
    int temp, cnt=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        if(isCheck(temp)) cnt++;
    }
    cout<<cnt;
}