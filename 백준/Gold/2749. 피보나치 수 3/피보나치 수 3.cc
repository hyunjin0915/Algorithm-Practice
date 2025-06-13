using namespace std;
#include <iostream>
#include <vector>

int main()
{
    long long n;
    cin>>n;
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    long long cnt = 2;
    while(true)
    {
        vec.push_back((vec[cnt] + vec[cnt-1] )% 1000000);
        cnt++;
        if(vec[cnt] == 0 && vec[cnt-1] == 1) break;
    }
    cout<<vec[n % cnt];

    return 0;
}