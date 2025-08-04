#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> names;
    
    for(string name : participant)
    {
        names.insert(name);
    }
    for(string name : completion)
    {
        auto a = names.find(name);
        names.erase(a);
    }
    return *names.begin();

}