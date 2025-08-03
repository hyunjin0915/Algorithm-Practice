class Solution {
public:
    #define INF 987654321
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        if(nums[0] == target) return 1;
        int sum = 0;
        int ans = INF;
        while(true)
        {
            if(right>=nums.size()) break;
            sum += nums[right++];
            while(sum >= target)
            {
                ans = min(ans,(right - left));
                sum -= nums[left];
                left++;
            }
        }
        return (ans == INF?0:ans);
    }
};