using namespace std;

#include <iostream>

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int M;
    cin>>M;
    int S = 0;
    string str;
    while(M--)
    {
        cin>>str;
        if(str=="add")
        {
            int num;
            cin>>num;
            num--;
            S = (S | (1<<num));
        }
        else if(str=="remove")
        {
            int num;
            cin>>num;
            num--;
            S = (S & ~(1<<num));
        }
        else if(str=="check")
        {
            int num;
            cin>>num;
            num--;
            int temp = (S & (1<<num));
            cout<<(temp?1:0)<<'\n';
        }
        else if(str=="toggle")
        {
            int num;
            cin>>num;
            num--;
            S = (S ^ (1<<num));
        }
        else if(str=="all")
        {
            S = (1<<20) -1 ;
        }
        else if(str=="empty")
        {
            S = 0;
        }
    }
 
    return 0;
}