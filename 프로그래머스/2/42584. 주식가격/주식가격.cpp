#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> st;
    answer.resize(prices.size(), 0);
    for(int i=0;i<prices.size();i++)
    {
        while(!st.empty() && (prices[i] < prices[st.top()]))
        {
            int index = st.top();
            st.pop();
            answer[index] = i - index;
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int index = st.top();
        answer[index] = (prices.size() - index - 1);
        st.pop();
    }
    return answer;
}