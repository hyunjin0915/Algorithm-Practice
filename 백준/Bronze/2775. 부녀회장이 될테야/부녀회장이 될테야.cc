#include <iostream>

using namespace std;

int main()
{
    int arr[15][15];
    int T, k, n;
    cin>>T;
    
    for(int i=0;i<=14;i++)
    {
        arr[0][i] = i;
    }
    for(int i=1;i<=14;i++)
    {
        for(int j=0;j<=14;j++)
        {
            if(j==0)
            {
                arr[i][j]=0;
                continue;
            }
            arr[i][j]=arr[i][j-1] + arr[i-1][j];
        }
    }
    for(int i=0;i<T;i++)
    {
        cin>>k>>n;
        cout<<arr[k][n]<<'\n';
    }
}