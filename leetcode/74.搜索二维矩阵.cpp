/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)
            return false;
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = m-1; j >= 0; j--) {
                if(matrix[i][j] == target)
                    return true;
                else if(matrix[i][j] < target)
                    break;
                else
                    continue;
            }
        }
        return false;
    }
};
// @lc code=end

