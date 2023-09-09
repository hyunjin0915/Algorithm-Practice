#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector <int> vec;
    vector <int> vAnswer;
    int N;
    cin>>N;
    
    for(int i=0;i<=N;i++)
    {
        string cmd;
        getline(cin, cmd);
        
        string cutCmd = cmd.substr(0,3);
        
        if(cutCmd=="pus")
        {
            int num = stoi(cmd.substr(5,cmd.size()-5));
            vec.push_back(num);
            continue;
        }
        else if(cutCmd=="pop")
        {
            if(vec.empty())
                {
                    vAnswer.push_back(-1);
                    continue;
                }
                vAnswer.push_back(vec.back());
                vec.pop_back();
                continue;
        }
        else if(cutCmd=="siz")
        {
            vAnswer.push_back(vec.size());
            continue;
        }
        else if(cutCmd=="top")
        {
            if(vec.empty())
            {
                vAnswer.push_back(-1);
                continue;
            }
            vAnswer.push_back(vec.back());
            continue;
        }
        else if(cutCmd=="emp")
        {
            if(vec.empty())
            {
                vAnswer.push_back(1);
                continue;
            }
            else
            {
                vAnswer.push_back(0);
                continue;
            }
        }
    }
    for(int i=0;i<vAnswer.size();i++)
    {
        cout<<vAnswer[i]<<'\n';
    }
}