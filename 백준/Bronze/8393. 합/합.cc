#include <iostream>
using namespace std;

int main()
{
    int n;
    int cnt = 0;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cnt+=i;
    }
    cout<<cnt;
}