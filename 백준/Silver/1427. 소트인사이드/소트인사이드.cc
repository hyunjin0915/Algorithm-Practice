#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(char a, char b)
{
    return a>b;
}

int main()
{
    vector<char> v;
    int N;
    cin>>N;
    string sNum;
    
    sNum = to_string(N);
    
    for(int i=0;i<sNum.length();i++)
    {
        v.push_back(sNum[i]);
    }
    sort(v.begin(),v.end(),desc);
    for(auto a : v)
    {
        cout<<a;
    }
    return 0;
}