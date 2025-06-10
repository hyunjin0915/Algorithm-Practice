using namespace std;
#include <iostream>
#include <cmath>
#define MOD 1000000007

long long fact[4000001];

long long power(long long a, long long b)
{
    if(b==0) return 1;
    long long half = power(a, b/2);
    long long result = half * half % MOD;
    if(b%2==1) result = result * a % MOD;
    return result;
    
}

long long Inv(int num)
{
    return power(num, MOD-2);
}

long long Combination(int n, int k)
{
    if(k<0 || k>n) return 0;
    return(fact[n] * Inv(fact[k]) % MOD * Inv(fact[n-k]) % MOD);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin>>N>>K;
    
    fact[0] = 1;
    for(int i=1;i<=N;i++)
    {
        fact[i] = fact[i-1] * i % MOD;
    }
    cout<< Combination(N,K);
}