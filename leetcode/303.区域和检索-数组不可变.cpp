/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include<vector>
class NumArray {
private:
    std::vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        preSum.resize(n+1, 0);
        for(int i = 1; i < n+1; i++) {
            preSum[i] = preSum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

