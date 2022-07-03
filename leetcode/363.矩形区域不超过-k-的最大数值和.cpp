/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 * Date: 2021-04-22
 */

// @lc code=start
#include<vector>
#include<set>
class Solution {
public:
    int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        std::vector<std::vector<int>> preSum(rowNum + 1, std::vector<int>(colNum + 1,0));
        for(int i = 1; i < rowNum+1; i++){
            for(int j = 1; j < colNum+1; j++){
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int res = INT_MIN;
        // 采取固定上下行 + 右边列的形式，这时候唯一能够确定一个子矩阵则是取决于 左边列 的位置
        for(int top = 1; top < rowNum+1; top++){
            for(int bot = top; bot < rowNum+1; bot++){
                // 有序集合是关键
                std::set<int> set;
                set.insert(0);
                //  枚举 目标子矩阵 右边列
                for(int r = 1; r < colNum+1; r++){
                    // 获取固定上下边后，子矩阵右边列和原矩阵左边列围城的面积
                    int right = preSum[bot][r] - preSum[top-1][r];
                    // right -left <= k --> left >= right -k 
                    // 二分法找 目标子矩阵 左边列
                    auto left = set.lower_bound(right - k);
                    if(left != set.end()){
                        int curr_area = right - *left;
                        res = max(res, curr_area);
                    }
                    set.insert(right);
                }
            }
        }
        return res;
    }
};
// @lc code=end

