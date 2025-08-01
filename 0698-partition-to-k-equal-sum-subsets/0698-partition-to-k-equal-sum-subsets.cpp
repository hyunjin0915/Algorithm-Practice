class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(),0);
        if(total % k !=0) return false;
        int target = total / k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > target) return false;

        vector<int> buckets(k, 0);
        return DFS(0, nums, buckets, target);
    }

    bool DFS(int idx, vector<int>& nums, vector<int>& buckets, int target)
    {
        if(idx == nums.size())
        {
            return true;
        }

        int cur = nums[idx];
        for(int i=0;i<buckets.size(); i++)
        {
            if(buckets[i] + cur <= target)
            {
                buckets[i] += cur;
                //성공 경로가 있으면 true 리턴
                if(DFS(idx +1, nums, buckets, target)) return true;
                buckets[i] -= cur; //백트래킹
            }
            if(buckets[i] == 0) break;

        }
        return false;
    }
};