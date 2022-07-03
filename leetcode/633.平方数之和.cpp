/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long low = 0;
        long high = sqrt((double)c);
        while (low <= high){
            long sum = low*low + high*high;
            if(sum == c)
                return true;
            else if(sum > c)
                high -= 1;
            else 
                low += 1;
        }
        return false;
        
    }
};
// @lc code=end

