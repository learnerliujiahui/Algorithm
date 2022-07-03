/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include<vector>
class Solution {
public:
    /* 查找旋转数组最小值位置 */
    int findRotateIndex(int l, int r, std::vector<int>& nums) {
        int left = l;
        int right = r;
        int mid = l;  //
        // if(nums[left] < nums[right])
        //     return 0;
        while(nums[left] > nums[right]) {
            if(right == left + 1)
                return right;
            mid = (left + right) >> 1;
            if(nums[mid] > nums[left])
                left = mid;
            else
                right = mid;
        }
        /* 数组未旋转，则直接返回0 */
        return mid;
    }
    /* 标准二分查找 */
    int BinarySearch(int l, int r, int target, std::vector<int>& nums) {
        int left = l;
        int right = r;
        int mid = l;
        while(left <= right) {
            mid = (left + right) >> 1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
            return (target == nums[0])? 0:-1;
        int rotateIndex = findRotateIndex(0, nums.size()-1, nums);
        if(rotateIndex == 0)
            return BinarySearch(0, nums.size()-1, target, nums);
        else {
            if(target >= nums[0])
                return BinarySearch(0, rotateIndex-1, target, nums);
            else
                return BinarySearch(rotateIndex, nums.size()-1, target, nums);
        }
    }
};
// @lc code=end

