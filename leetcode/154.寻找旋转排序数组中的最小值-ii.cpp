/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 * 
 * Date:2021-04-09
 */

// @lc code=start
#include<vector>

class Solution {
public:
    int findRotateIndex(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(nums[left] >= nums[right]) {
            if(left+1 == right)
                return right;
            mid = (left + right) >> 1;
            if(nums[left] == nums[mid] && nums[mid] == nums[right]) {
                for(int i = left+1; i < right+1; i++) {
                    if(nums[i] < nums[i-1])
                        return i;
                }
                /* 考虑到left == right的情况 */
                return 0;
            }
            if(nums[mid] >= nums[left])
                left = mid;
            else
                right = mid;
        }
        /* 考虑数组未进行旋转的情况 */
        return 0;
    }
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int minIndex = findRotateIndex(nums);
        return nums[minIndex];
    }
};
// @lc code=end

