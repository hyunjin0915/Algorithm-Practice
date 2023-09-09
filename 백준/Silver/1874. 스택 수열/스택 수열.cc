#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    stack<int> s;
    vector<char> v;
    

    int N;
    cin>>N;
    
    int num = 1;
    int k;

    s.push(0); //
    
    for(int i=1;i<=N;i++) //n번의숫자입력받음
    {
        cin>>k;
        while(s.top()<k)
        {
            s.push(num);
            num++;
            v.push_back('+');
        }
        if(s.top()==k)
        {
            s.pop();
            v.push_back('-');
        }
        else
        {
            cout<<"NO"<<'\n';
            return 0;
        }
    }
   
   for(auto it : v)
   {
       cout<<it<<'\n';
   }
}