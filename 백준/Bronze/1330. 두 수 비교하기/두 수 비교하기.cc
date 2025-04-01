using namespace std;
#include <iostream>

int main()
{
    int A, B;
    cin>>A >> B;
    
    if(A>B)
    {
        cout<<">";
    }
    else if(A<B)
    {
        cout<<"<";
    }
    else
    {
        cout<<"==";
    }
}