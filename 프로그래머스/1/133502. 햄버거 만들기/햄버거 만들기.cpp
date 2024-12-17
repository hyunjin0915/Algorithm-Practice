#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string s = "";
    for(auto a : ingredient)
        s+=to_string(a);
    string ham = "1231";
    int pos = 0;
    while((pos = s.find(ham,pos))!=std::string::npos)
    {
       s= s.substr(0,pos) + s.substr(pos+4,s.size());
        pos-=1;
       if(pos>2) pos-=3;
       answer++;
    }

    return answer;
}