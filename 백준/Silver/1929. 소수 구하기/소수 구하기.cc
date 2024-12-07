#include <iostream>
#include <cmath>
using namespace std;

int main()
{
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin>>M>>N;
    bool arr[1000001] = {false,};
    arr[1] =true;
    for(int i=2;i<=sqrt(N);++i)
    {
        if(arr[i]) continue;
        else
        {
            for(int j=i+i;j<=N;j+=i)
            {
                arr[j] = true;
            }
        }
        
    }
    for(int i=M;i<=N;++i)
    {
        if(!arr[i]) cout<<i<<'\n';
    }
}