#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    for(int i=1;i<=elements.size();i++)
    {
        for(int j=0;j<elements.size();j++)
        {
            int sum = 0;
            for(int k=j;k<j+i;k++)
            {
                sum += elements[(k%elements.size())];
            }
            s.insert(sum);
        }
    }
    answer = s.size();
    return answer;
}