#include <iostream>

using namespace std;

int arr[129][129];
int white = 0;
int blue = 0;

void fc(int x, int y, int size)
{
    bool cut = false;
    int first_color = arr[x][y];
    for(int i=x; i<x+size;i++)
    {
        for(int j=y;j<y+size;j++)
        {
            if(arr[i][j]!=first_color)
            {
                cut=true;
                break;
            }
        }
    }
    if(cut)
    {
        fc(x,y,size/2);
        fc(x,y+size/2,size/2);
        fc(x+size/2,y,size/2);
        fc(x+size/2,y+size/2,size/2);
    }
    else
    {
        if(first_color==1) blue++;
        else white++;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    fc(0,0,n);
    cout<<white<<'\n';
    cout<<blue<<'\n';
    return 0;
}