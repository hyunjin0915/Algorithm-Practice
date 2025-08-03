class Solution {
public:
    vector<int> nums;
    int k;
    bool check(int mid)
    {
        int cnt = 1;
        int cur = 0;
        for(int x : nums)
        {
            if(cur + x > mid)
            {
                cnt++;
                cur = x;
            }
            else
            {
                cur += x;
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& _nums, int _k) {
        nums = _nums;
        k = _k;
        long long sum = 0;
        int lo = 0;
        for(int n : nums)
        {
            lo = max(lo, n);
            sum += n;
        }
        while(lo < sum)
        {
            int mid = (lo + sum) /2;
            if(check(mid)) sum = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};