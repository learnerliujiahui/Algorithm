/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *  1. 按行检索
 *  2. 按列检索：对于当前列关注左边最高的墙和右边最高的强
 *  3. 按
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int res = 0;
        int left_max = 0;
        std::vector<int> right_max(height.size());

        for(int i = height.size()-2; i >= 0; i--){
            right_max[i] = (right_max[i+1]>height[i+1])?right_max[i+1]:height[i+1];
        }

        for(int i = 1; i < height.size()-1; i++){
            left_max = (left_max>height[i-1])?left_max:height[i-1];
            int shortEdge = (left_max < right_max[i])?left_max:right_max[i];
            if(shortEdge > height[i])
                res += shortEdge-height[i];
        }
        return res;
    }
};
// @lc code=end

