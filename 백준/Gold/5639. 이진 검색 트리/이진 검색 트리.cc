using namespace std;
#include <iostream>
#include <vector>

int nums[10001] = {0};
vector<int> answer;

void post(int start, int end)
{
    if(start >= end) return;
    
    int root = nums[start];
    int delim = start + 1;
    
    while(delim<end)
    {
        if(root < nums[delim]) break;
        delim++;
    }
    
    post(start+1, delim);
    post(delim, end);
    
    cout<<root<<'\n';
}


int main()
{
    int n;
    int index = 0;
    while(cin>>n)
    {
        nums[index++] = n;
    }
    
    post(0, index);
    return 0;
}