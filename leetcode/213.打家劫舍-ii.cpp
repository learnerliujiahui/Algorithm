/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 * Date: 2021-04-15
 * 动态规划
 * 递推关系：d[i] = max(d[i-2]+s[i], d[i-1])
 */

// @lc code=start
#include<vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        std::vector<int> dp1(n, 0);
        std::vector<int> dp2(n, 0);

        // 偷第一个房子 dp[0] 预设为0
        dp1[1] = nums[0];
        for(int i = 2; i < n; i++) {
            dp1[i] = max(dp1[i-2]+nums[i-1], dp1[i-1]);
        }
        // 不偷第一房子
        dp2[1] = nums[1];
        for(int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i-2]+nums[i], dp2[i-1]);
        }

        return max(dp1[n-1], dp2[n-1]);
    }
};
// @lc code=end

