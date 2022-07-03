/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include<vector>
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int max_area = 0, tmp_area = 0;
        while (i < j) {
            if(height[i] < height[j]){
                tmp_area = height[i]*(j-i);
                i++;
            }
            else {
                tmp_area = height[j]*(j-i);
                j--;
            }
            max_area = max(max_area, tmp_area);
        }
        return max_area;
    }
};
// @lc code=end

