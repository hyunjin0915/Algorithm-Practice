using namespace std;
#include <iostream>

int n;
int arr[41] = {0, };
int cnt1 = 0;
int cnt2 = 0;

void dpFibo()
{
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++)
    {
      cnt2++;
      arr[i] = arr[i-1] + arr[i-2];

    }
}

int recurFibo(int a)
{
    if(a==1 || a==2)
    {
        cnt1++;
        return 1;
    }
    else
    {
        return (recurFibo(a-1) + recurFibo(a-2));
    }
}


int main()
{
    cin>>n;
    int answer = recurFibo(n);
    dpFibo();
    cout<<cnt1<<" "<<cnt2;

    return 0;
}