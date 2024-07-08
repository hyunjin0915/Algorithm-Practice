using namespace std;

#include <iostream>
#include <cmath>

bool check(int num);

int main()
{
    int M, N;
    cin>>M>>N;
    
    int cnt = 0;
    int min;
    
    
    for(int i=M;i<=N;i++)
    {
        if(check(i))
        {
            if(cnt==0) min = i;
            cnt += i;
        }
    }
    if(cnt==0)
    {
        cout<<"-1";
    }
    else
    {
        cout<< cnt <<'\n'<<min;
    }
}

bool check(int num)
{
    if(num == 1) return false;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}