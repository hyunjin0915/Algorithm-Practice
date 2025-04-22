using namespace std;
#include <iostream>
#include <vector>

int N;
pair<char, char> arr[26];


void preOrder(char x)
{
    if(x!='.')
    {
        cout<<x;
        preOrder(arr[x- 'A'].first);
        preOrder(arr[x- 'A'].second);
    }
    else return;
}
void inOrder(char x)
{
    if(x!='.')
    {
        inOrder(arr[x- 'A'].first);
        cout<<x;
        inOrder(arr[x- 'A'].second);
    }
    else return;
}
void postOrder(char x)
{
    if(x!='.')
    {
        postOrder(arr[x- 'A'].first);
        postOrder(arr[x- 'A'].second);
        cout<<x;
    }
    else return;
}

int main()
{
    cin>>N;
     
    for(int i=0;i<N;i++)
    {
        char a,b,c;
        cin>>a>>b>>c;
        arr[a - 'A'].first = b;
        arr[a-'A'].second = c;
    }
    preOrder('A');
    cout<<'\n';
    inOrder('A');
    cout<<'\n';
    postOrder('A');
    
}