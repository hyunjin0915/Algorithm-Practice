using namespace std;
#include <iostream>

int N;
int arr[100001];
int heapCnt = 0;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Add(int num)
{
    arr[++heapCnt] = num;
    int child = heapCnt;
    int parent = heapCnt/2;
    while(child>1 && arr[child]>arr[parent])
    {
        swap(&arr[child], &arr[parent]);
        child = parent;
        parent = child/2;
    }
}
int Pop()
{
    int root = arr[1];
    arr[1] = arr[heapCnt];
    heapCnt-=1;
    int parent = 1;
    int child = parent * 2;
    if(child+1 <= heapCnt)
    {
        child = (arr[child] > arr[child+1]) ? child : child+1;
    }
    while(child <= heapCnt && arr[child]> arr[parent])
    {
        swap(&arr[child], &arr[parent]);
        parent = child;
        child = parent*2;
        if(child+1 <= heapCnt)
        {
            child = (arr[child] > arr[child+1]) ? child : child+1;
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
        int n;
        cin>>n;
        if(n==0)
        {
            if(heapCnt==0)
            {
                cout<<0<<'\n';
            }
            else
            {
                cout<<Pop()<<'\n';
                continue;
            }
        }
        else
        {
        Add(n);
            
        }
    }

    return 0;
}