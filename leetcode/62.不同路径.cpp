/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 * 
 * Date:2021-03-30
 * 
 * d[i][j]: 到达第i行，第j列需要多少步
 * 
 * d[i][j] = d[i-1][j] + d[i][j-1];
 */

// @lc code=start
#include<vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int> > dp_table(m, std::vector<int> (n, 0));
        // dp_table 初始化
        for(int i = 0; i < m; i++) {
            dp_table[i][0] = 1;
        }
        for(int j = 0; j < n; j++) {
            dp_table[0][j] = 1;
        }
        // 开始生成dp_table
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1];
            }
        }
        return dp_table[m-1][n-1];
    }
};
// @lc code=end

