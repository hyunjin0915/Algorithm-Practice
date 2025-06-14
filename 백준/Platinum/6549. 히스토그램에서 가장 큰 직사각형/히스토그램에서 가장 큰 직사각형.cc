#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<long long> h(n + 1); // 마지막에 높이 0 추가
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        h[n] = 0; // 강제 마무리를 위해 추가

        stack<int> st;
        long long maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && h[st.top()] > h[i]) {
                long long height = h[st.top()];
                st.pop();
                long long width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        cout << maxArea << '\n';
    }
    return 0;
}
