/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 * Date:2021-04-19
 * 有点儿快排 partition 的思想
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int curr = -1;
        int next = 0;
        while(next < nums.size()) {
            if(nums[next] != val)
                nums[++curr] = nums[next];
            next++;
        }
        return ++curr;
    }
};
// @lc code=end

