#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    queue<int> q; 
    int N,K;
    cin>>N>>K;
    vector<int> vec;
    
    int num = 1;
    while(N--)
    {
        q.push(num++);
    }
    
    while(!q.empty())
    {
        int cnt = K;
        while(cnt>1)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            cnt--;
        }
        vec.push_back(q.front());
        q.pop();
    }
    cout<<"<";
    for(int i=0;i<vec.size()-1;i++)
    {
        cout<<vec[i]<<", ";
    }
    cout<<vec[vec.size()-1];
    cout<<">";
}