/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 * Date: 2021-05-05
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>

class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) 
            return 0;
        // 构建元素数量数组
        int maxNum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxNum = (nums[i] > maxNum)?nums[i]:maxNum;
        }
        std::vector<int> sumNum(maxNum+1, 0);
        for(int i = 0; i < nums.size(); i++) {
            sumNum[nums[i]]++;
        }
        // 构建dp-table
        // dp[i] 表示截止i为止，可以获得的最大点数
        std::vector<int> dp(maxNum+1, 0);
        dp[1] = sumNum[1];
        for(int i = 2; i < maxNum+1; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+sumNum[i]*(i));
        }
        return dp[maxNum];
        
    }
};
// @lc code=end

