/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 * Date: 2021-04-01
 * 还可以研究下基于快排partion的方法
 */

// @lc code=start
#include<vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        while(index < n) {
            nums[index++] = 0;
        }
        
    }
};
// @lc code=end

