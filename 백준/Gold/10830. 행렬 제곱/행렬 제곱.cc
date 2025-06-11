using namespace std;
#include <iostream>
#include<vector>

long long N, B;
vector<vector<int>> identity;
vector<vector<int>> A;

vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<vector<int>> C(N, vector<int>(N, 0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            long long sum = 0;
            for(int k=0;k<N;k++)
            {
                sum += (long long)A[i][k] * B[k][j];
            }
            C[i][j] = sum % 1000;
        }
    }
    return C;
}

vector<vector<int>> matPow(vector<vector<int>> &A, long long exp)
{
    if(exp == 0) return identity;
    
    auto half = matPow(A, exp/2);
    auto cal = multiply(half, half);
    if(exp %2==0)
    {
        return cal;
    }
    else
    {
        return multiply(cal, A);
    }
    
}
int main()
{
    cin>>N>>B;
    identity.resize(N, vector<int>(N,0));
    for(int i=0;i<N;i++)
    {
        identity[i][i] = 1;
    }
    A.resize(N, vector<int>(N,1));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>A[i][j];
        }
    }
    auto result = matPow(A, B);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<result[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}