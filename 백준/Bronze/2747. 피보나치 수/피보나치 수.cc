using namespace std;

#include <iostream>

int main()
{
    int arr[45];
    int N;
    cin>>N;
    
    arr[0]=0;
    arr[1]=1;
    
    for(int i=2;i<=45;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    cout<<arr[N];
}