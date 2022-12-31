#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int num=0;
    int cnt=0;
    vector<int> v;
    vector<int> cntv;
    for(int i=1;i<=cards.size();i++)
    {
        if(find(v.begin(),v.end(),i)!=v.end()) continue;
        else
        {
            v.push_back(i);
            num = cards[i-1];
            cnt++;
            while(i!=num)
            {
               v.push_back(num);
               num = cards[num-1];
               cnt++;
                
            } 
        }
      cntv.push_back(cnt);
      cnt=0;
    }
    sort(cntv.rbegin(),cntv.rend());
    answer = cntv[0]*cntv[1];
    return answer;
}