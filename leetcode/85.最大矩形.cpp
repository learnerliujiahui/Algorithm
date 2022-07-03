/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 * date: 2021-11-25
 * method: 动态规划
 */

// @lc code=start
#include<vector>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        std::vector<std::vector<int>> d(n, std::vector<int>(m, 0));
        

    }
};
// @lc code=end

