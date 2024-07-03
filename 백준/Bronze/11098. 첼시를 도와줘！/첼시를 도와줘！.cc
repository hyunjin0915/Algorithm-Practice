#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, p;
    int price;
    string name;
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        int max_price = 0;
        string max_name = "";
        for(int j=0;j<p;j++)
        {
            cin>>price;
            cin>>name;
            if(price>max_price)
            {
                max_price = price;
                max_name = name;
            }
        }
        cout<<max_name<<'\n';
    }
}