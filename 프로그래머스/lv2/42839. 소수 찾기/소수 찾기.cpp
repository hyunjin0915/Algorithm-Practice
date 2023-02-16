#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int changeNum(vector<int> v);
bool findPNum (int num);

int solution(string numbers) {
    int answer = 0;
    vector <int> nums;
    set <int> s;
    for(int i=0;i<numbers.size();i++)
    {
        nums.push_back(numbers[i]-'0');
    }
    vector <int> temp (nums.size(),0);
    for(int j=0;j<nums.size();j++)
    {
        temp[j]=1;
        
        do{
            vector<int> tv;
            for(int i=0;i<nums.size();++i)
            {
                if(temp[i]==1)
                {
                    tv.push_back(nums[i]);
                }
            }
            sort(tv.begin(),tv.end());
            do{
                vector<int> ttv;
                for(int k=0;k<tv.size();k++)
                {
                    ttv.push_back(tv[k]);
                    cout<<tv[k];
                }
                cout<<"/";
                s.insert(changeNum(ttv));
                //if(findPNum(changeNum(ttv))) answer++;
            }while(next_permutation(tv.begin(),tv.end()));
            
        }while(prev_permutation(temp.begin(),temp.end()));    
    }
    for(auto it:s)
    {
        int nn = it;
        if(findPNum(nn))answer++;
    }
    return answer;    
}
int changeNum(vector<int> v)
{
    int num=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        num+=v[i]*pow(10,i);
    }
    return num;
}
bool findPNum (int num)
{
    if(num==1||num==0) return false;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0) return false;
    }
    return true;
}