/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 * Date: 2021-03-31
 * METHOD: 回溯法
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
    std::vector<std::vector<int> > res;
    std::vector<int> path;
    // 还需额外维护一个表示每一个元素是否使用过的备忘录
    std::vector<bool> used;

public:
    void DFS(int index, int target_num, std::vector<int>& nums) {
        // 回溯终止条件
        if(path.size() == target_num) {
            res.push_back(path);
            return;
        }
        // 遍历候选集合
        for(int i = index; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            DFS(i+1, target_num, nums);
            path.pop_back();
            used[i] = false;
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 初始化 元素使用 备忘录
        used.resize(nums.size(), false);
        res.push_back({});
        // 排序，便于去重
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); i++) {
            DFS(0, i, nums);
        }
        return res;
    }
};
// @lc code=end

