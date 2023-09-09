#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    string str;
    cin>>str;
    
    int num = 0; //현재막대개수
    bool isR = false;
    int cnt = 0;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            num+=1;
            cnt+=1;
            isR = true;
        }
        if(str[i]==')')
        {
            if(isR) //만약레이저면
            {
                num-=1;
                cnt-=1;
                cnt += num;
                isR=false;
                continue;
            }
            num-=1;
        }
    }
    
    cout<<cnt;
}