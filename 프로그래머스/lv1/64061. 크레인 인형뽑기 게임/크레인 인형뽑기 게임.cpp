#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
      int answer = 0;
    
    int col = board[0].size(); //열길이
    int row = board.size(); //헹
   // cout<<col << "  "<<row;
    
    vector<int> save;
  /*  for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(board[i][j]!=0){
                save.push_back(board[i][j]);
             while(save[save.size()-1]==save[save.size()-2])
             {
                 save.pop_back(); save.pop_back();
                 answer++;
             }          
            } 
        }
    }*/

    for(int j=0;j<moves.size();j++){
        for(int i=0;i<row;i++){
           if(board[i][moves[j]-1]!=0)
           {
            save.push_back(board[i][moves[j]-1]);
          
            while(save[save.size()-1]==save[save.size()-2])
             {
                 save.pop_back(); save.pop_back();
                 answer++;
             } 
             board[i][moves[j]-1]=0;
            break;
           } 
            //continue;
        }

    }
    
      
    for(int i=0;i<save.size();i++){
        cout<<save[i]<<" ";
    }
    return answer*2;
}