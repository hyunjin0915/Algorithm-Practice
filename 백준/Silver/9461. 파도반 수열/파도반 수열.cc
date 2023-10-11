#include <iostream>

using namespace std;
long long arr[101] = {0,1,1,};

long long fibo(int N)
{
    if(N<3)
        return arr[N];
    else if(arr[N]==0)
    {
        arr[N] = fibo(N-3) + fibo(N-2);
    }
    return arr[N];
}

int main()
{
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        cout<<fibo(N)<<'\n';
    }

    return 0;
}