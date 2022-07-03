/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // 前制 空格 便于统一的处理逻辑
        s = " " + s;
        // def dp_table[i] --> 前i个字符串的解码方案数
        std::vector<int> dp_table(n+1, 0);
        dp_table[0] = 1;
        for(int i = 1; i < n+1; i++) {
            int a = (int)s[i]-'0';
            int b = ((int)s[i-1]-'0')*10 + a;
            if(a>=1 && a<=9)
                dp_table[i] = dp_table[i-1];
            if(b>=10 && b <=26)
                dp_table[i] += dp_table[i-2];
        }
        return dp_table[n];
    }
};
// @lc code=end

