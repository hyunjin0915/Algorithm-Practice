/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using namespace std;

#include <iostream>
#include <vector>
#include <queue>

vector<vector<int>> fam;
vector<bool> visited;
int n, a, b, m;

void BFS()
{
    queue<pair<int, int>> q;
    q.push({a, 0});
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        visited[node.first] = true;
        if(node.first==b)
        {
            cout<<node.second;
            return;
        }
        
        for(auto k : fam[node.first])
        {
            if(!visited[k])
                q.push({k, node.second+1});
        }
    }
    cout<<-1;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    fam.resize(n+1);
    visited.resize(n+1, false);
    
    cin>>a>>b;
    cin>>m;
    while(m--)
    {
        int x, y;
        cin>>x>>y;
        fam[x].push_back(y);
        fam[y].push_back(x);
    }
    
    BFS();
    return 0;
}