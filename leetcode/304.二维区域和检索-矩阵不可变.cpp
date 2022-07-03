/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 * Date: 2021-04-22
 * 二维前缀和
 */

// @lc code=start
#include<vector>
class NumMatrix {
private:
    std::vector<std::vector<int> > preSum;
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        preSum.resize(rowNum+1, std::vector<int>(colNum+1, 0));
        for(int i = 1; i < rowNum+1; i++) {
            for(int j = 1; j < colNum+1; j++) {
                preSum[i][j] = preSum[i][j-1] + preSum[i-1][j] -preSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] -preSum[row2+1][col1] - preSum[row1][col2+1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

