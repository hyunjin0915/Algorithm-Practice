class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums)
        {
            sum += n;
        }
        if(sum %2!=0) return false;
        int target = sum/2;
        vector<bool> dp(target+1 , 0);
        dp[0] = true;
        for(int i=0;i<nums.size();i++)
        {
            for(int j = target; j >= nums[i]; j--)
            {
                dp[j] = dp[j-nums[i]] || dp[j];
            }
        }
        return dp[target];
    }
};