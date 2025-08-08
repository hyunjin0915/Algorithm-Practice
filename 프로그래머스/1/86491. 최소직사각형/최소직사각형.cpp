#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int a = 0;
    int b = 0;
    for(auto cards : sizes)
    {
        a = max(a, max(cards[0], cards[1]));
        b = max(b, min(cards[0], cards[1]));
        
    }
    return a*b;
}