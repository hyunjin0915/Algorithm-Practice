using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    vector<int> num;
    num.resize(3, 0);
    while(true)
    {
        for(int i=0;i<3;i++)
        {
            cin>>num[i];
        }
        if(num[0]==0 && num[1]==0 && num[2]==0) break;
        sort(num.begin(), num.end());
        if(num[2]>=num[0] + num[1])
        {
            cout<<"Invalid"<<'\n';
            continue;
        }
        if(num[0]==num[1] || num[1]==num[2])
        {
            if(num[0]==num[2])
            {
                cout<<"Equilateral"<<'\n';
                continue;
            }
            cout<<"Isosceles"<<'\n';
            continue;
        }
        cout<<"Scalene"<<'\n';
    }
}