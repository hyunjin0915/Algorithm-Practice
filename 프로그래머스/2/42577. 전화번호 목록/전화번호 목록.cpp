#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s;
    for(string num : phone_book)
    {
        s.insert(num);
    }
    for(string num : phone_book)
    {
        string check = "";
        for(int i=0;i<num.size()-1;i++)
        {
            check += num[i];
            if(s.find(check)!=s.end()) return false;
        }
    }
   
    return true;
}