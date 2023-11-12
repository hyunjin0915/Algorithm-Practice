#include <iostream>
using  namespace std;

pair<char,char> arr[26];

void preOrder(char x) //전
{
    if (x != '.')
    {
        cout << x;
        preOrder(arr[x - 'A'].first);
        preOrder(arr[x - 'A'].second);
    }
    else return;
}
void inOrder(char x) //중
{
    if (x != '.')
    {
        inOrder(arr[x - 'A'].first);
        cout << x;
        inOrder(arr[x - 'A'].second);
    }
    else return;
}
void postOrder(char x) //
{
    if (x != '.')
    {
        postOrder(arr[x - 'A'].first);
        postOrder(arr[x - 'A'].second);
        cout << x;

    }
    else return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char a,b,c;
        cin >> a >> b >> c;

        arr[(a - 'A')].first = b;
        arr[(a - 'A')].second = c;
    }
    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
    
}