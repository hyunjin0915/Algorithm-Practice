using namespace std;

#include <iostream>

int main()
{
    long long arr[91];
    int N;
    cin>>N;
    
    arr[0]=0;
    arr[1]=1;
    
    for(int i=2;i<=90;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    cout<<arr[N];
}