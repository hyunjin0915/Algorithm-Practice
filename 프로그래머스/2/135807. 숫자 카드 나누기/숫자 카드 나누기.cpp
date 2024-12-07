#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int hahaha(vector<int> array);

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.rbegin(),arrayA.rend());
    sort(arrayB.rbegin(),arrayB.rend());
    int a = hahaha(arrayA);
    int b = hahaha(arrayB);
    cout<<a<<b;
    bool checka = true;
    for(int i=0;i<arrayA.size();i++)
    {
        if(arrayA[i]%b==0) {checka=false; break;}
        else checka = true;
    }
    bool checkb = true;
    for(int i=0;i<arrayB.size();i++)
    {
        if(arrayB[i]%a==0) {checkb=false; break;}
        else checkb=true;
    }
  
    if(checka==true&&checkb==true) answer = a>b?a:b;
    else if (checka) return b;
    else if(checkb) return a;
    else return 0;
    return answer; 
    }

int hahaha(vector<int> array)
{
    bool check = true;
    for(int i=array[array.size()-1];i>=2;i--)
    {
        check=true;
        for(int j=0;j<array.size();j++)
        {
            if(array[j]%i!=0)
            {
                check=false;
                break;
            }
        }
        if(check) return i;
        
    }
    
   
}


