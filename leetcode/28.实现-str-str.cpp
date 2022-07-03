/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if(needle.size() == 0)
            return 0;
        if(haystack.size() < needle.size())
            return -1;
        int i = 0;
        int j = 0;
        while(i <= haystack.size()-needle.size()) {
            while(j < needle.size() && haystack[i+j] == needle[j]) {
                j++;
            }
            if(j == needle.size())
                return i;
            else {
                j = 0;
                i++;
            }
        }
        return -1;
    }
};
// @lc code=end

