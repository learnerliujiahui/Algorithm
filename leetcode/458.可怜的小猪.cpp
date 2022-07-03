/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 * date: 2021-11-25
 * 
 */

// @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(k+1));
    }
};
// @lc code=end

