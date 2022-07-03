/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        
        std::vector<int> dp(n+1, 0);

        dp[1] = nums[0];

        for(int i = 2; i < n+1; i++) {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};
// @lc code=end

