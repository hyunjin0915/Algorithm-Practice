#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[3] = {1, 1, 0};
int dy[4] = {0, 1, 1 };

bool visited[31][31] = {false,};
vector<vector<char>> arr;

bool check(int i, int j)
{
    char c = arr[i][j];
    if(c!='X' &&arr[i][j+1] == c && arr[i+1][j] == c
       && arr[i+1][j+1] == c) 
        return true;
    else
        return false;
}
void move(int m, int n)
{
    for(int i=m-1; i>=0; i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(arr[i][j]=='X')
            {
                int y = i;
                while(y>=0)
                {
                    if(arr[y][j]!='X')
                    {
                        arr[i][j] = arr[y][j];
                        arr[y][j] = 'X';
                        break;
                    }
                    else y--;
                }
            }
        }
    }
}

int remove(int m, int n)
{
    map<pair<int, int>, bool> ma;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+1<m && j+1<n && check(i,j))
            {
                ma.insert({make_pair(i,j), true});
                ma.insert({make_pair(i,j+1), true});
                ma.insert({make_pair(i+1,j), true});
                ma.insert({make_pair(i+1,j+1), true});
            }
        }
    }
    for(auto a = ma.begin(); a!=ma.end(); a++)
    {
        arr[a->first.first][a->first.second] = 'X';
    }
    return ma.size();
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    arr.resize(m, vector<char>(n,'a'));
    for(int i=0 ; i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = board[i][j];
        }
    }
    
    while(1)
    {
        int eraseCnt = 0;
        eraseCnt = remove(m, n);
        if(eraseCnt !=0)
        {
            answer += eraseCnt;
            move(m, n);
        }
        else break;
    }
    return answer;
}