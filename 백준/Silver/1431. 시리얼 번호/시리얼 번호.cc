#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cntSum(string str)
{
    int sum = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] >='0' && str[i] <='9')
        {
            sum+=(str[i]-'0');
        }
    }
    return sum;
}
bool func(string a, string b)
{
    if(a.length()!=b.length())
        return a.length()<b.length();
        
    else if(a.length()==b.length())
    {
        int Sa, Sb;
        Sa = cntSum(a);
        Sb = cntSum(b);
        if(Sa!=Sb)
            return Sa<Sb;
    }
    
    return a<b;
}
int main()
{
    int N;
    cin>>N;
    vector<string> v;
   
    for(int i=0;i<N;i++)
    {
        string s="";
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),func);
    
    for(auto a : v)
    {
        cout<<a<<'\n';
    }
    return 0;
}