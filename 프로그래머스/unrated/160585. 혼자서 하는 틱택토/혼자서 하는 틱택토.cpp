#include <string>
#include <vector>


using namespace std;

bool isT(char a, char cc[][3])
{
    if(cc[0][0]==a&&cc[0][1]==a&&cc[0][2]==a) return true;
    if(cc[1][0]==a&&cc[1][1]==a&&cc[1][2]==a) return true;
    if(cc[2][0]==a&&cc[2][1]==a&&cc[2][2]==a) return true;
    
    if(cc[0][0]==a&&cc[1][0]==a&&cc[2][0]==a) return true;
    if(cc[0][1]==a&&cc[1][1]==a&&cc[2][1]==a) return true;
    if(cc[0][2]==a&&cc[1][2]==a&&cc[2][2]==a) return true;
    
    if(cc[0][0]==a&&cc[1][1]==a&&cc[2][2]==a) return true;
    if(cc[2][0]==a&&cc[1][1]==a&&cc[0][2]==a) return true;
    else return false;
}

int solution(vector<string> board) {
    int Ocnt = 0;
    int Xcnt = 0;
    
    char c [3][3] = {'.'};
    for(int i=0;i<board.size();i++)
    {
        const char* ch = board[i].c_str();
        for(int j=0;j<3;j++)
        {
            c[i][j] = ch[j];
            if(c[i][j]=='O') Ocnt++;
            if(c[i][j]=='X') Xcnt++;
        }            
    }

    if(Ocnt!=Xcnt && Ocnt!=Xcnt+1) return 0;
    
    if(isT('O',c))
    {
        if(Ocnt-1!=Xcnt) return 0;
    }
    else if(isT('X',c))
    {
        if(Xcnt!=Ocnt) return 0;
    }
    if(isT('O',c) && isT('X',c) && Ocnt-1==Xcnt) return 0;
    return 1;
}