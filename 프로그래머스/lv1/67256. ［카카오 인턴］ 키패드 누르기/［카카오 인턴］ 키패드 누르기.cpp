#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
     string answer = "";
    int L2=4,R2=4,L5=3,R5=3,L8=2,R8=2,L0=1,R0=1;
    
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] == 1) {
            answer.push_back('L');
            L2=1; L5=2; L8=3; L0=4; 
        }
        else if(numbers[i]==4) {
            answer.push_back('L');
            L2=2; L5=1; L8=2; L0=3; 
        }
        
        else if(numbers[i]==7) {
            answer.push_back('L');
            L2=3; L5=2; L8=1; L0=2;
        }
                
        else if(numbers[i]==3) {
            answer.push_back('R');
            R2=1; R5=2; R8=3; R0=4;
        }
        else if(numbers[i]==6) {
            answer.push_back('R');
            R2=2; R5=1; R8=2; R0=3;
        }
        else if(numbers[i]==9) {
            answer.push_back('R');
            R2=3; R5=2; R8=1; R0=2;
        }
        /////////////////
        else if(numbers[i]==2){
            if(L2<R2 || (L2==R2 && hand=="left")) { answer.push_back('L'); L5=1;L8=2;L0=3; L2=0;}
            else if(L2>R2|| (L2==R2 && hand=="right")) {answer.push_back('R'); R5=1;R8=2;R0=3; R2=0;}          
        }
        else if(numbers[i]==5){
            if(L5<R5||(L5==R5 && hand=="left")) { answer.push_back('L'); L2=1;L8=1;L0=2; L5=0;}
            else if(L5>R5||(L5==R5 && hand=="right")) { answer.push_back('R'); R2=1;R8=1;R0=2; R5=0;}
          //  else if(L5==R5 && hand=="left") answer.push_back('L');
           // else answer.push_back('R');      
        }
        else if(numbers[i]==8){
            if(L8<R8||(L8==R8 && hand=="left")) { answer.push_back('L'); L2=2;L5=1;L0=1; L8=0;}
            else if(L8>R8||(L8==R8 && hand=="right")) { answer.push_back('R');  R2=2;R5=1;R0=1; R8=0;}
               
        }
        else if(numbers[i]==0){
            if(L0<R0||(L0==R0 && hand=="left")) { answer.push_back('L'); L2=3;L5=2;L8=1; L0=0;}
            else if(L0>R0||(L0==R0 && hand=="right")) { answer.push_back('R');  R2=3;R5=2;R8=1; R0=0;}
            
        
        }
    }
   
    return answer;
}