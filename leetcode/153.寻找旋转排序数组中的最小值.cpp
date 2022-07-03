/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    /* 利用二分法 */
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(nums[left] > nums[right]) {
            if(left + 1 == right)
                return nums[right];
            mid = (left + right) >> 1;
            if(nums[mid] > nums[left])
                left = mid;
            else
                right = mid;
        }
        /* 如果数组未进行旋转 */
        return nums[0];
    }
};
// @lc code=end

