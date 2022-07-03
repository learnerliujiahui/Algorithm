/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // date: 2021-06-13
    int firstBadVersion(int n) {
        // binary-search

        long left = 0;
        long right = n;
        long mid = left;
        while (left < right)
        {
            mid = (left + right) / 2;
            if(isBadVersion(mid) == true)
                right = mid;
            else
                left = mid+1;
        }
        return right;

    }
};
// @lc code=end

