#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int N,M;
    cin>>N>>M;
    
    if(N<M)
    {
        int temp;
        temp = N;
        N = M;
        M = temp;
    }
    
    int gcdNum = gcd(N,M);
    int lcmNum = N*M/gcdNum;
    cout<<gcdNum<<endl<<lcmNum<<endl;

}