using namespace std;
#include <iostream>

int main()
{
    
    int N;
    cin>>N;
    
    int answer = 1;
    for(int i=1;i<=N;i++)
    {
        answer *=i;
    }
    
    cout<<answer;
}