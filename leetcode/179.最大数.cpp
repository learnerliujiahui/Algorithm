/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
#include<queue>
#include<string>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> strs;
        for(auto num: nums) {
            strs.push_back(to_string(num));
        }

        auto cmp = [](std::string left, std::string right) {
            return left+right > right+left;
        };

        sort(strs.begin(), strs.end(), cmp);

        std::stringstream ss;
        for(auto str: strs) {
            ss << str;
        }
        std::string res = ss.str();
        if(res[0] == '0')  // 消除全0情况
            return "0";
        return res;
    }
};
// @lc code=end

