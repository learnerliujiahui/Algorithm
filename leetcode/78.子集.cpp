/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 * Date: 2021-03-31
 */

// @lc code=start
#include<vector>

class Solution {
private:
    std::vector<std::vector<int> > res;
    std::vector<int> path;
public:
    void DFS(int index, int target_num, vector<int>& nums) {
        // 回溯终止条件
        if(path.size() == target_num){
            res.push_back(path);
            return;
        }

        // 开始遍历不同选择路径
        // 将符合条件的路径加入到结果候选集中
        for(int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            DFS(i+1, target_num, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        for(int i = 1; i <= nums.size(); i++) {
            DFS(0, i, nums);
        }
        return res;
    }
};
// @lc code=end

