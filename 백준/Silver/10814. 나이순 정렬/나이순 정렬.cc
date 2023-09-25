#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Member{
public:
    string name;
    int age;
    int num;
    Member(int num,string name, int age):num(num),name(name),age(age){}
};

bool func(Member a, Member b)
{
    if(a.age==b.age) return a.num<b.num;
    else
    {
        return a.age<b.age;
    }
}


int main()
{
    vector<Member> v;
    
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int age;
        string name;
        cin>>age;
        cin>>name;
        v.push_back(Member(i,name,age));
    }
    
    sort(v.begin(),v.end(),func);
    
    for(auto m : v)
    {
        cout<<m.age<<" "<<m.name<<'\n';
    }
}