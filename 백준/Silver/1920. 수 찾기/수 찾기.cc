using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin>>N;
    vector<int> A;
    A.resize(N);
    int k;
    for(int i=0;i<N;i++)
    {
        cin>>k;
        A[i] = k;
    }
    sort(A.begin(),A.end());
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>k;
        int start = 0;
        int end = N-1;
        bool isFind = false;
        while(start <= end)
        {
            int midIndex = (start+end)/2;
            int mid = A[midIndex];
            if(mid>k)
            {
                end = midIndex-1;
            }
            else if(mid<k)
            {
                start = midIndex+1;
            }
            else
            {
                isFind = true;
                break;
            }
        }
        if(isFind) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}