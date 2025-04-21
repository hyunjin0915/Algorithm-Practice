#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int index = 1;
    int cnt = 2;
   // int arr[1001]={0,};
    queue<int> q;
    q.push(numbers[0]);
    q.push(-numbers[0]);
    
    while(index<numbers.size())
    {
        for(int i=0; i<cnt;i++ )
        {
            int front_node = q.front();
            q.pop();
            q.push(front_node + numbers[index]);
            q.push(front_node - numbers[index]);
            
           // if(front_node - numbers[index]>0)   arr[front_node - numbers[index]]++;
            //if(front_node + numbers[index]>0)   arr[front_node + numbers[index]]++;
            
        }
        cnt*=2;
        index++;
    }
    
    while(!q.empty())
    {
        int num = q.front();
        if(num==target) answer++;
        q.pop();
    }
   
    return answer;
}