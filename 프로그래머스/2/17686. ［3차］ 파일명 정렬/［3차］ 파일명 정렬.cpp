#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class fileInfo{
     public :
     int index;
     string head;
     int number;
};

vector<fileInfo> vec;

bool cmp(fileInfo f1, fileInfo f2)
{
    if(f1.head == f2.head)
    {
        if(f1.number == f2.number)
        {
            return f1.index < f2.index;
        }
        return f1.number < f2.number;
    }
    return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(int i=0;i<files.size();i++)
    {
        string str = files[i];
        string words = "";
        string num = "";
       vector<int> vv;
        for(int j=0;j<str.size();j++)
        {
            
           if(str[j]>='0' && str[j]<='9')
            {
                vv.push_back(j);
            }
        }
        for(int j=0;j<vv[0];j++)
        {
            words += tolower(str[j]);
        }
        num = str.substr(vv[0], vv.size());
        fileInfo f;
        f.index = i;
        f.head = words;
        f.number = stoi(num);
        vec.push_back(f);
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i=0;i<vec.size();i++)
    {
        answer.push_back(files[vec[i].index]);
    }
    return answer;
}