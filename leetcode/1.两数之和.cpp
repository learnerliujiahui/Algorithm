/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start'
#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash_table;
        for(int i = 0; i < nums.size(); i++) {
            if(hash_table.find(target-nums[i]) == hash_table.end()) {
                hash_table[nums[i]] = i;
            } else {
                
                return {hash_table.find(target-nums[i])->second, i};
            }
        }
        return {};
    }
};
// @lc code=end

