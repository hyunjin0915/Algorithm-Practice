using namespace std;

#include <queue>
#include <iostream>
#include <set>

int N, K;
int answer = 0;

int BFS(string str)
{
    if(str.size()==1|| (str.size() == 2 && str[1] == '0')) return -1;
    
    queue<string> q;
    q.push(str);
    
    for(int depth = 0; depth <K; depth++)
    {
        int s = q.size();
        if(s==0) return -1;
        set<string> visited;
        
        while(s--)
        {
            string front = q.front();
            q.pop();
            for(int i=0;i<front.size()-1;i++)
            {
                for(int j=i+1;j<front.size();j++)
                {
                    if(i==0 && front[j] == '0') continue;
                    string temp = front;
                    swap(temp[i], temp[j]);
                    if(visited.find(temp) == visited.end())
                    {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            
        }
        
    }
    while(!q.empty())
    {
        answer = max(answer, stoi(q.front()));
        q.pop();
    }
    return answer;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>K;
    
    cout<<BFS(to_string(N));
    return 0;
}