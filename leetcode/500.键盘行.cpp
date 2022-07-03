/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 * Date: 2021-04-01
 */

// @lc code=start
#include<vector>
#include<map>
#include<string>

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        std::map<char, int> tb; 
        
        tb['q'] = 1;
        tb['w'] = 1;
        tb['e'] = 1;
        tb['r'] = 1;
        tb['t'] = 1;
        tb['y'] = 1;
        tb['u'] = 1;
        tb['i'] = 1;
        tb['o'] = 1;
        tb['p'] = 1;

        tb['a'] = 2;
        tb['s'] = 2;
        tb['d'] = 2;
        tb['f'] = 2;
        tb['g'] = 2;
        tb['h'] = 2;
        tb['j'] = 2;
        tb['k'] = 2;
        tb['l'] = 2;

        tb['z'] = 3;
        tb['x'] = 3;
        tb['c'] = 3;
        tb['v'] = 3;
        tb['b'] = 3;
        tb['n'] = 3;
        tb['m'] = 3;
        std::vector<std::string> res;
        for(int i = 0; i < words.size(); i++) {
            if(words[i].size() == 1){
                res.push_back(words[i]);
                continue;
            }
            for(int j = 0; j < words[i].size(); j++) {
                if(j == words[i].size()-1)
                    res.push_back(words[i]);
                if(j+1 < words[i].size() && tb[tolower(words[i][j])] == tb[tolower(words[i][j+1])])
                    continue;
                else
                    break;
            }
        }
        return res;
    }
};
// @lc code=end

