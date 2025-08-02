class Solution {
public:
    vector<int> buckets;
    int target;
    vector<int> matchsticks;
    bool makesquare(vector<int>& _matchsticks) {
        int sum = 0;
        matchsticks = _matchsticks;
        sort(matchsticks.rbegin(), matchsticks.rend());
        buckets.resize(4, 0);
        for(int s : matchsticks)
        {
            sum += s;
        }
        if(sum%4 != 0) return false;
        target = sum/4;
        return DFS(0);
    }
    bool DFS(int idx)
    {
        if(idx == matchsticks.size())
        {
            for(int a : buckets)
            {
                if(a != target) return false;
            }
            return true;
        }
        for(int i = 0;i<buckets.size();i++)
        {
            if(buckets[i]+ matchsticks[idx] > target)
            {
                continue;
            }

            buckets[i] += matchsticks[idx];
            if(DFS(idx+1)) return true;
            buckets[i] -= matchsticks[idx];

            if(buckets[i]==0) break;
        }
        return false;
    }
};