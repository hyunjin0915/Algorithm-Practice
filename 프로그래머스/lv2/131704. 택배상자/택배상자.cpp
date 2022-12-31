#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int n = 1; //컨테이너벨트에서나오는상자번호
    stack<int> save; //보조컨테이너벨트
    for(int i=0;i<order.size();i++)
    {
        if(order[i]>n)
        {
           while(order[i]!=n)
           {
           save.push(n);
           n++;
           } 
            answer++;
            n++;
            continue;
        } 
        else if(order[i]<n)
        {
            if(order[i]==save.top())
            {
                answer++; 
                save.pop();
                continue;
            }
            else break;
        }
        else if(order[i]==n){
            answer++;
            n++;
        } 
        else break;
    }
   
    return answer;
}