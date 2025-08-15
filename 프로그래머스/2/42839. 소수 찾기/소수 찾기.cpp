#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> digits;
set <int> numSet;
vector<bool> visited;

bool Check(int num)
{
    if(num == 0 || num == 1) return false;
    for(int i=2; i*i <= num; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

void DFS(int depth, int count)
{
    if(depth>0) numSet.insert(count);
    
    for(int i=0;i<digits.size();i++)
    {
        if(!visited[i])
        {
            if(i>0 && digits[i-1]==digits[i] && !visited[i-1]) continue;
            visited[i]=true;            
            DFS(depth+1, count*10 + digits[i]);
            visited[i] = false;
        }
    }
}


int solution(string numbers) {
    int answer = 0;
    
    for(int i=0;i<numbers.size();i++)
    {
        digits.push_back(numbers[i]-'0');
    }
    visited.resize(numbers.size(),false);
    
    sort(digits.begin(), digits.end());
    DFS(0, 0);
    
    for(int a : numSet)
    {
        if(Check(a)) answer++;
    }
    return answer;
}