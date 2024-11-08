#include <string>
#include <vector>

using namespace std;

int solution(std::vector<int> a) {
    int answer = 0;
    vector<int> vec;
    vec.resize(a.size(),0);
    for(auto num : a)
    {
        vec[num] ++;
    }
    for(int i=0;i<vec.size();i++)
    {
        int cnt = 0;
        if(vec[i]<= answer) continue;
        else
        {
            for(int j=0;j<a.size()-1;j++)
            {
                if((a[j]==i||a[j+1]==i)&& a[j] != a[j+1])
                {
                    cnt++;
                    j++; //!!
                }
            }
        }
        answer = max(answer , cnt);
    }
    return answer*2;
}