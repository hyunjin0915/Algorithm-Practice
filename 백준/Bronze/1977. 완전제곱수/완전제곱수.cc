#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int M, N;
	cin >> M>>N;
    
    int sum = 0;
    int min_num=10001;
    for(int i=1;i<=100;i++)
    {
        int num = pow(i,2);
        if(num>=M && num<=N)
        {
            if(min_num>=num) min_num = num;
            sum+=num;
        }
    }
    if(sum == 0)
    {
        cout<<"-1";
        return 0;
    }
    cout<<sum<<endl<<min_num;    
}