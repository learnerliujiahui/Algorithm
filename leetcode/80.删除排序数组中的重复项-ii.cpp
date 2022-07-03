/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 * Date: 2021-04-06
 * 实际上实现的是C++的remove函数
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int curr = 0;
        int next = 1;
        bool du = false;
        while(next < n) {
            if(nums[curr] == nums[next]) {
                // 前后元素相等（不一定相邻）但还需要继续判断是否已经是第三个相邻元素
                if(du == false) {
                    nums[++curr] = nums[next];  // 注意是++curr
                    du = true;
                }
                // 若是第三个相邻元素，则curr指针不动，next指针后移
            } 
            else {
                nums[++curr] = nums[next];
                du = false;
            }
            next++;
        }
        return ++curr;
    }
};
// @lc code=end

