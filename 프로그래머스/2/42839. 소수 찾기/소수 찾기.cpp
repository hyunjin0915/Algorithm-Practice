#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<bool> primes;
vector<int> digits;
set<int> numset;
vector<bool> visited;

void DFS(int depth, int count)
{
    if(depth>0) numset.insert(count);
    
    for(int i=0;i<digits.size();i++)
    {
        if(!visited[i])
        {
            if(depth==0 && digits[i]==0) continue;
            if(i>0 && digits[i-1]==digits[i] && !visited[i-1]) continue;
            visited[i] = true;
            DFS(depth+1, count*10 + digits[i]);
            visited[i]=false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    int size = numbers.size();
    visited.resize(size, false);
    
    string str = "";
    for(int i=0;i<size;i++)
    {
        str += '9';
        digits.push_back(numbers[i]-'0');
    }
    sort(digits.begin(), digits.end());
    
    int max = stoi(str);
    primes.resize(max, true);
    primes[0] = false;
    primes[1] = false;
    
    for(int i=2;i*i<=max;i++)
    {
        if(!primes[i]) continue;
        for(int j = i*i; j<=max; j+= i)
        {
            primes[j] = false;
        }
    }
    
    DFS(0, 0);
    
    for(int n : numset)
    {        
        if(primes[n]) answer++;
    }
    return answer;
}