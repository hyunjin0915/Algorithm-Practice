class Solution {
public:
    int best = 1e9;

    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.rbegin(), cookies.rend());
        vector<int> buckets(k, 0);
        DFS(0, cookies, buckets);

        return best;
    }

    void DFS(int idx, vector<int> cookies, vector<int> buckets)
    {
        if(idx == cookies.size())
        {
            int curMax = 0;
            for(int b : buckets)
            {
                curMax = max(curMax, b);
            }
            best = min(best, curMax);
            return;
        }

        for(int i = 0; i<buckets.size(); i++)
        {
            if(best <= buckets[i] + cookies[idx]) continue;
            buckets[i] += cookies[idx];
            DFS(idx+1, cookies, buckets);
            buckets[i] -= cookies[idx];

            if(buckets[i] == 0)
            {
                break;
            }
        }
    }
};