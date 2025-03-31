using namespace std;
#include <iostream>
#include <vector>

vector<pair<int,int>>vec;
void hanoi(int n, int start, int temp, int end)
{
    if(n==1)
    {
        vec.push_back(make_pair(start, end));
        return;
    }
    else
    {
        hanoi(n-1, start, end, temp);
        vec.push_back(make_pair(start, end));
        hanoi(n-1, temp, start, end);
    }
}

int main()
{
    int N;
    cin>>N;
    hanoi(N, 1, 2, 3);
    cout<<vec.size()<<"\n";
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second<<"\n";
    }
    return 0;
}