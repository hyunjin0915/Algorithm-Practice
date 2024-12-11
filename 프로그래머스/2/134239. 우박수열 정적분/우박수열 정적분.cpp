#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> vec;
    vector<double> area;
    while(k!=1)
    {
        vec.push_back(k);
        if(k%2==0) {k=k/2;}
        else {k=k*3+1;}
    }
    vec.push_back(1);
    for(int i=0;i<vec.size()-1;i++)
    {
        double w = (vec[i]+vec[i+1])/2.0;
        area.push_back(w);
    }
    for(int i=0;i<ranges.size();i++)
    {
        int left = ranges[i][0];
        int right = ranges[i][1]+area.size();
        if(right<left) {answer.push_back(-1); continue;}
        double sum =0.0;
        for(int j=left;j<right;j++)
        { 
            sum+=area[j];
        }
        answer.push_back(sum);
    }
    return answer;
}