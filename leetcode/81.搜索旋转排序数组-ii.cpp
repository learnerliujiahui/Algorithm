/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 * Date: 2021-04-08
 * [33] 题扩展：引入了数字重复的情况
 */

// @lc code=start
#include<vector>

class Solution {
public:
    int findRotateIndex(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(nums[left] >= nums[right]) {  // 加入=因为考虑了有重复数字的情况
            if(left + 1 == right)
                return right;
            mid = (left + right) >> 1;
            /* 单独讨论无法应用二分法的情况 */
            if(nums[left] == nums[mid] && nums[mid] == nums[right]) {
                for(int i = left+1; i < right+1; i++) {
                    if(nums[i] < nums[i-1])
                        return i;
                }
                /* 考虑到left == right的极端情况 */
                return left;
            }
            /* 正常二分法策略 */
            if(nums[mid] >= nums[left])
                left = mid;
            else
                right = mid;
        }
        /* 数组未旋转的情况 */
        return 0;
    }
    bool binarySearch(int l, int r, int target, std::vector<int>& nums) {
        int left = l;
        int right = r;
        int mid = l;
        while(left <= right) {
            mid = (left + right) >> 1;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        /* 一个元素情况必须单独讨论 */
        // if(nums.size() == 1)
        //     return nums[0] == target;
        int minIndex = findRotateIndex(nums);
        if(target < nums[minIndex])
            return false;
        if(minIndex == 0)
            return binarySearch(0, nums.size()-1, target, nums);
        else {
            if(target >= nums[0])
                return binarySearch(0, minIndex-1, target, nums);
            else
                return binarySearch(minIndex, nums.size()-1, target, nums);
        }
    }
};
// @lc code=end

