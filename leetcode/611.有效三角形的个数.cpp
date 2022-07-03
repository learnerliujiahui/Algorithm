/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 * date: 2021-03-27
 */

// @lc code=start
#include<algorithm>

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // 先排序
        if(n < 3)
            return 0;
        int count = 0;
        /**
         * 
         * O(n^2) 双指针
        */
        for(int k = n-1; k > 1; k--) {
            int left = 0;
            int right = k-1;
            while(left < right) {
                /**
                 * 如果nums[i] + nums[j] > nums[k]
                 * 则说明一直到j-1都存在：
                 *    nums[j-1] + nums[j] > nums[k]
                 * 一共有j-1-i+1 = j-i个，同时j左移，进入下一轮
                 * 
                */
                if(nums[left] + nums[right] > nums[k]) {
                    count += right - left;
                    right--;
                }
                else 
                    left++;
            }
        }
        /**
         * 
         * O(n^2logn) 双循环+二分法
        */

        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         int target = nums[i] + nums[j];
        //         int left = j+1;
        //         int right = n-1;
        //         int mid = left;
        //         while(left < right) {
        //             mid = (left+right+1) / 2;
        //             if(nums[mid] >= target)
        //                 right = mid-1;
        //             else
        //                 left = mid;
        //         }
        //         if(nums[right] < target)
        //             count += right-j;
        //     }
        // }
        return count;
    }
};
// @lc code=end

