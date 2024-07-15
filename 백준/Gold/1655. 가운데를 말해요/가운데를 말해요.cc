#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    vector<int> answer;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num, pq_size;
        cin >> num;

        if (max.size() == min.size())
        {
            max.push(num);
        }
        else
        {
            min.push(num);
        }
        if (!max.empty() && !min.empty() && max.top() > min.top())
        {
            int max_val, min_val;
            max_val = max.top();
            min_val = min.top();
            max.pop();
            min.pop();
            max.push(min_val);
            min.push(max_val);
        }
        cout << max.top() << '\n';
    }
}