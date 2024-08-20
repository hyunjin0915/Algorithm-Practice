#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    bool Loof = true;
    while(Loof)
    {
        int ta, tb;
        ta = a;
        tb = b;
        if(ta%2==0)
        {
            if(ta-1==tb) Loof = false;
            a/=2;
        }
        else
        {
            //if(a +1 = b) Loof = false;
            if(ta != 1)
            {
                a = a/2+1;
            }
        }
        if(tb%2==0)
        {
            if(tb-1==ta) Loof = false;
            b/=2;
        }
        else if(tb!=1) b = b/2+1;
        answer++;
    }
    cout << "Hello Cpp" << endl;

    return answer;
}