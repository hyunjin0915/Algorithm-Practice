using namespace std;
#include <iostream>
#include <vector>


int H,W,N,M;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>H>>W>>N>>M;
    
    int cnt = 0;
    for(int i=0;i<H;i+=N+1)
    {
        for(int j=0;j<W;j += M+1)
        {
            cnt++;
        }
    }
    cout<<cnt;
}