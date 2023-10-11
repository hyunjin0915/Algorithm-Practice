#include <iostream>
using namespace std;

int arr[41];

int fibo(int num)
{
    if(num<=1)
    {
        arr[num]=num;
        return arr[num];
    }
    if(arr[num]!=0)
    {
        return arr[num];
    }
    else
    {
        arr[num] = fibo(num-1) + fibo(num-2);
        return arr[num];
    }
}


int main()
{
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        
        fibo(N);
        if(N==0)
            cout<<1<<' '<<0<<'\n';
        else if(N==1)
            cout<<0<<' '<<1<<'\n';
        else
            cout<<arr[N-1]<<' '<<arr[N]<<'\n';
    }
    
    return 0;
}