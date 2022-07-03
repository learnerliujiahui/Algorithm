/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
#include<string>

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        if(n <= 1)
            return true;
        bool LL_flag = false;
        int absent_time = 0;
        int last_time = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') {
                if(last_time < 2)
                    last_time++;
                else
                    LL_flag = true;
            } 
            else {
                last_time = 0;
                if(s[i] == 'A')
                    absent_time++;
            }
        }
        return absent_time < 2 && !LL_flag;
    }
};
// @lc code=end

