/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 * Date:2021-04-04
 * 数学技巧性强
 */

// @lc code=start
#include<algorithm>
#include<vector>

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int res = 0;
        for(int i = 0; i < answers.size(); i++){
            int cnt = answers[i];
            res += cnt + 1;
            int k = cnt;
            while (k-- > 0 && i+1 < answers.size()&& answers[i]==answers[i+1]){
                i++;  
            }
        }
        return res;    
    }
};
// @lc code=end

