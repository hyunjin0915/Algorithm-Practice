using namespace std;
#include <iostream>
#include <map>

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int N;
    cin>>N;
    
    map<int, int> m;
    int num;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        m[num]++;
    }
    
    int M;
    cin>>M;
    
    for(int i=0;i<M;i++)
    {
        cin>>num;
        cout<<m[num]<<' ';
    }
    return 0;
}