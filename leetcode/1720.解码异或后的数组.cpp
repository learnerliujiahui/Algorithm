/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 * Date: 2021-05-06
 */

// @lc code=start
#include<vector>
class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        std::vector<int> res;
        res.push_back(first);
        if(encoded.size() == 0)
            return res;
        int curr_value = first;
        for(auto num: encoded) {
            curr_value = num ^ curr_value;
            res.push_back(curr_value);
        }
        return res;
    }
};
// @lc code=end

