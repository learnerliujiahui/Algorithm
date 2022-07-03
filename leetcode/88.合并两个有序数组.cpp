/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 * Date: 2021-04-05
 * 方法：逆向双指针
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 边界条件判断
        if(n == 0)
            return;
        int p = m-1;
        int q = n-1;
        int index = m+n-1;
        while(p >= 0 || q >= 0) {
            if(p == -1)
                nums1[index--] = nums2[q--];
            else if(q == -1)
                nums1[index--] = nums1[p--];
            else if(nums1[p] >= nums2[q])
                nums1[index--] = nums1[p--];
            else
                nums1[index--] = nums2[q--];
        }
        return;
    }
};
// @lc code=end

