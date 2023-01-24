#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a=0;
    int b=0;
    int c=0;
    for(int i=1;i<=answers.size();i++)
    {
        if((i%5)==answers[i-1]) a++;
        if((i%5==0)&&answers[i-1]==5)a++;
        if(i%2==1) //홀수번째
        {
            if(answers[i-1]==2) b++;
        }
        else//짝수번째
        {
            if(i%8==2&&answers[i-1]==1)b++;
            if(i%8==4&&answers[i-1]==3)b++;
            if(i%8==6&&answers[i-1]==4)b++;
            if(i%8==0&&answers[i-1]==5)b++;
        }
        if(i%10==1&&answers[i-1]==3)c++;
        if(i%10==2&&answers[i-1]==3)c++;
        if(i%10==3&&answers[i-1]==1)c++;
        if(i%10==4&&answers[i-1]==1)c++;
        if(i%10==5&&answers[i-1]==2)c++;
        if(i%10==6&&answers[i-1]==2)c++;
        if(i%10==7&&answers[i-1]==4)c++;
        if(i%10==8&&answers[i-1]==4)c++;
        if(i%10==9&&answers[i-1]==5)c++;
        if(i%10==0&&answers[i-1]==5)c++;
    }
    if(a>=b&&a>=c)
    {
        answer.push_back(1);
        if(a==b) answer.push_back(2);
        if(a==c) answer.push_back(3);
        return answer;
    }
    else if(b>=a&&b>=c)
    {
        answer.push_back(2);
        if(b==a) answer.push_back(1);
        if(b==c) answer.push_back(3);
        sort(answer.begin(),answer.end());
        return answer;
    }
    else if(c>=b&&c>=a)
    {
        answer.push_back(3);
        if(c==b) answer.push_back(2);
        if(a==c) answer.push_back(1);
        sort(answer.begin(),answer.end());
        return answer;
    }
}