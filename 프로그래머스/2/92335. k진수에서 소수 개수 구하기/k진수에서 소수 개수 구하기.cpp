#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

bool isPrime(long long n)
{
    if(n==0 || n==1) return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string str = "";
    while(n>0)
    {
        long long num = n%k;
        str += to_string(num);
        n/=k;
    }
    reverse(str.begin(),str.end());
    
    string ss = "";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='0')
        {
            if(ss.length()==0) continue; 
            if(isPrime(stol(ss))) answer++;
            ss="";
            continue;
        }
        ss += str[i];  
    }
    if(ss.length()!=0)
    {
        if(isPrime(stol(ss))) answer++;
    }
    
    return answer;
}