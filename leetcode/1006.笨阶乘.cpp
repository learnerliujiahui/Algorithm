/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 * Date: 2021-04-01
 */

// @lc code=start
#include<stack>

class Solution {
public:
    int clumsy(int N) {
        int res_sum = 0;
        std::stack<int> s;
        s.push(N);
        N--;
        int i = 0;
        while(N > 0) {
            if(i == 0)
                s.top() *= N;
            else if(i == 1)
                s.top() /= N;
            else if(i == 2)
                s.push(N);
            else 
                s.push(-1*N);
            N--;
            i++;
            i = i % 4;
        }
        while(s.empty() == false) {
            res_sum += s.top();
            s.pop();
        }
        return res_sum;
    }
};
// @lc code=end

