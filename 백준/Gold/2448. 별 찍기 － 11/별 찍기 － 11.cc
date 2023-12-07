#include <iostream>

using namespace std;

char map[3072][6144];

void R(int x, int y, int height)
{
    if(height==3)
    {
        map[x][y] = '*';
        map[x+1][y-1]='*';
        map[x+1][y+1]='*';
        for(int i=y-2;i<=y+2;i++)
        {
            map[x+2][i]='*';
        }
        return;
    }
    R(x,y,height/2);
    R(x+height/2,y-height/2,height/2);
    R(x+height/2,y+height/2,height/2);
}

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            map[i][j]=' ';
        }
    }
    R(0,n-1,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
    return 0;
}