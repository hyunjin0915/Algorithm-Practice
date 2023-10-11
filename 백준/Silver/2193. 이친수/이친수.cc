#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    long D[91][2];
    
    D[1][1] = 1;
    D[1][0] = 0;
    
    for(int i=2;i<=N;i++)
    {
        D[i][1] = D[i-1][0];
        D[i][0] = D[i-1][1] + D[i-1][0];
    }
    
    cout<<D[N][0] + D[N][1];
}