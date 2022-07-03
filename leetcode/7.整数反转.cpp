/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 * 2021-03-29
 */

// @lc code=start
class Solution {
public:
    /**
     * 分析: 
     * x的最高位反转后变为y的最低位
     * 对于符号需要特殊处理吗？
    */
    int reverse(int x) {
        int y = 0;  // 用来承接反转后的数字
        while (x != 0) {
            // 考虑栈溢出的临界情况
            if(y > pow(2,31)/10 || y < -1*pow(2,31)/10)
                return 0;
            y = y * 10 + x%10;
            x /= 10;  
        }
        return y;
    }
};
// @lc code=end

