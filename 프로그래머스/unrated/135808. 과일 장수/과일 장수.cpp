#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end());
    int n = score.size()/m; //n개의 박스 만들기 가능
    int index = score.size();
    
    while(index>=m){
        index -= m;
        answer+=score[index]*m;
    }
    return answer;
}