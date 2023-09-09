#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,K,i=0;
    string num;
    vector<char> v;
    cin>> N>> K;
    cin>>num;
    
    while(i != num.size())
    {
        while(K!=0 && !v.empty() && v.back() < num[i] )
        {
            v.pop_back();
            K--;
        }
        v.push_back(num[i]);
        i++;
    }
    while(K--)
    {
        v.pop_back();
    }
    for(auto it:v)
    {
        cout<<it;
    }
}