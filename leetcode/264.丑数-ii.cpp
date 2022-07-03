/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include<queue>
#include<vector>

class Solution {
public:
    /**
     * 
     * 基本原理：
     * 丑数一定由1，2，3，5这四个因数组成
     * 那么将这几个数随意组合相乘，再排序，就找到了最小的
     * 
    */
    int nthUglyNumber(int n) {
        long res = 1;
        std::priority_queue<long, std::vector<long>, std::greater<long> > Q;
        for(int i = 1; i < n; i++) {
            Q.push(res*2);
            Q.push(res*3);
            Q.push(res*5);
            res = Q.top();
            Q.pop();
            // 用于去重
            while(!Q.empty() && res == Q.top())
                Q.pop();
        }
        return res;
    }
};
// @lc code=end

