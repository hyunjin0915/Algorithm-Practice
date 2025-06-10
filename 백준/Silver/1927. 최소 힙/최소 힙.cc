/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using namespace std;
#include <iostream>

int arr[100001];
int N;
int heapCnt = 0;

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b= tmp;
}

void Add(int num)
{
    arr[++heapCnt] = num;
      int child = heapCnt;
        int parent = heapCnt/2;
        while(arr[child] < arr[parent] && parent >=1 )
        {
            Swap(&arr[child], &arr[parent]);
            child = parent;
            parent = child/2;
        }
    
}

int Pop()
{
    int root = arr[1];
    Swap(&arr[1] , &arr[heapCnt]);
    heapCnt-=1;
    int parent = 1;
    int child = parent * 2;
    
    if(child + 1 <= heapCnt)
    {
        child = (arr[child]<arr[child + 1])? child: child + 1;
    }
    
    while(arr[parent] > arr[child] && child <= heapCnt)
    {
        Swap(&arr[child], &arr[parent]);
        parent = child;
        child = parent*2;
        if(child + 1 <= heapCnt)
        {
            child = (arr[child]<arr[child + 1])? child: child + 1;
        }
    }
    
    return root;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N;
    while(N--)
    {
        int x;
        cin>>x;
        if(x==0)
        {
            if(heapCnt == 0)
            {
                cout<<0<<'\n';
            }
            else
            {
                cout<<Pop()<<'\n';
            }
        }
        else
        {
            Add(x);
        }
    }
}