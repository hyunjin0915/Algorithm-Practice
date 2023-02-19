#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int index1 = 0;
    int index2 = 0;
    for(int i=0;i<goal.size();i++)
    {
        if(cards1[index1]==goal[i])
            index1++;
        else if(cards2[index2]==goal[i])
            index2++;
        else
            return "No";
    }
    return "Yes";
}