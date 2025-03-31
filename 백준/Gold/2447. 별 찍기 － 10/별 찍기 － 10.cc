using namespace std;
#include <iostream>

void dot(int i, int j, int n)
{
    if((i/n) % 3 == 1 && (j/n) % 3 == 1)
    {
        cout<<' ';
    }
    else if(n / 3 == 0)
    {
        cout<<'*';
    }
    else
    {
        dot(i, j, n/3);
    }
    return;
}

int main()
{
    int N;
    cin>>N;
    
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dot(i, j, N);
        }
        cout<<'\n';
    }
}
