#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool checkArr[123456*2+1]={false};
    checkArr[1] = true;
    checkArr[0] = true;
    for(int i=2;i<=sqrt(123456*2);i++)
    {
        if(checkArr[i]==false)
        {
            for(int j=i+i;j<=123456*2;j+=i)
            checkArr[j]=true;
        }
    }
    while(true)
    {
        int N, cnt=0;
        cin>>N;
        if(N==0)break;
        for(int i=N+1;i<=N*2;i++)
        {
            if(!checkArr[i]) cnt++;
        }
        cout<<cnt<<endl;
        cnt=0;
    }
}