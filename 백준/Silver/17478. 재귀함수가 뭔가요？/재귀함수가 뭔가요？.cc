/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

string line = "____";

void repeat(int n, int k)
{
    string s = "";
    int val = k - n;
    while(val--) s+= line;
    
    cout<<s<<"\"재귀함수가 뭔가요?\"\n";
    
    if(n==0)
    {
        cout<<s<<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cout<<s<<"라고 답변하였지.\n";
        return;
    }
    else
    {
        cout<<s<<"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        cout<<s<<"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        cout<<s<<"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        
        
        repeat(n-1, k);
        
        cout<<s<<"라고 답변하였지.\n";
        return;
    }
    
}

int main()
{
    int k;
    cin>>k;
    cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    repeat(k,k);
}