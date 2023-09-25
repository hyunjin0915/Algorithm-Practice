
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <int> s;
    
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int k;
        cin>>k;
        s.insert(k);
    }
    for(auto num : s)
    {
        cout<<num<<'\n';
    }
    return 0;
}