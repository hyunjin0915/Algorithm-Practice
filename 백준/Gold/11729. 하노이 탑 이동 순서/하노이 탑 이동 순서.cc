#include <iostream>

using namespace std;

void hanoi(int n, int start, int end, int temp)
{
    if(n==1)
        cout<<start<<" "<<end<<'\n';
    else
    {
        hanoi(n-1, start, temp, end);
        cout<<start<<" "<<end<<'\n';
        hanoi(n-1, temp, end, start);
    }
}
int main()
{
    int num;
    cin>>num;
    cout<<(1<<num) -1 <<'\n';
    hanoi(num, 1,3,2);
}