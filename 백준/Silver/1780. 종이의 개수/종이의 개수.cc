#include <iostream>

using namespace std;

int map[2200][2200];
int zeNum = 0;
int moNum = 0;
int oNum = 0;
void check(int x,int y, int size)
{
    bool cut = false;
    int firstNum = map[x][y];
    for(int i=x;i<x+size;i++)
    {
        for(int j=y;j<y+size;j++)
        {
            if(map[i][j]!=firstNum)
            {
                cut = true;
                break;
            }
        }
        if(cut) break;
    }
    
    if(cut)
    {
        check(x, y, size / 3); 
        check(x+size/3, y, size / 3); 
        check(x+size/3+size/3, y, size / 3); 
        check(x, y+size/3, size / 3); 
        check(x, y+size/3+size/3, size / 3); 
        check(x+size/3, y+size/3, size / 3); 
        check(x+size/3+size/3, y+size/3+size/3, size / 3);
        check(x+size/3, y+size/3+size/3, size / 3); 
        check(x+size/3+size/3, y+size/3, size / 3);
    }
    else
    {
        if(map[x][y]==0) zeNum++;
        else if(map[x][y]==1) oNum++;
        else moNum++;
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
           cin>> map[i][j];
        }
    }
    check(0,0,n);
    cout<<moNum<<'\n'<<zeNum<<'\n'<<oNum<<'\n';
    return 0;
}