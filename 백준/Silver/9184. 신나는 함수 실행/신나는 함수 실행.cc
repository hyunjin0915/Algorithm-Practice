using namespace std;
#include <iostream>

int dp[51][51][51] = {0, };

int w(int a, int b, int c)
{
    if(dp[a][b][c] != 0)
    {
        return dp[a][b][c];
    }
    
    if(a<=0 || b<=0 || c<=0)
    {
        return 1;
    }
    
    else if(a > 20 || b>20 || c>20)
    {
        dp[a][b][c] = w(20, 20, 20);
        //return (dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c]);
        //return w(20, 20, 20);
        //return dp[20][20][20];
    }
    
    else if(a<b && b<c)
    {
        dp[a][b][c] =(w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c));
        //return (w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c));
    }
    else
    {
        //return (dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1]);
        dp[a][b][c] = (w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1));
    }
    return dp[a][b][c];

}

int main()
{
    int x, y, z;
    
    while(true)
    {
        cin>>x>>y>>z;
        if(x ==-1 && y ==-1 && z ==-1) break;
        if(x<=0 || y<=0 || z<=0)
        {
            cout<<"w("<<x<<", "<<y<<", "<<z<<") = ";
            cout<<1<<'\n';
        }
        else
        {
            cout<<"w("<<x<<", "<<y<<", "<<z<<") = ";
            cout<<w(x,y,z)<<'\n';
        }
    }
    
    
    

    return 0;
}