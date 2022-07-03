/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 * date: 2022-01-06
 * method: 回溯
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
class Solution {
private:
    std::vector<int> segments;
    std::vector<std::string> res;
public:
    void DFS(std::string& s, int tmp_size, int s_start) {
        // 递归终止条件, 找到了一个合法ip地址 or 遍历完全部的字符
        if(tmp_size == 4) {
            if(s_start == s.size()) {
                std::string tmp_ip;
                for(int i = 0; i < 4; i++) {
                    tmp_ip += to_string(segments[i]);
                    if(i != 3)
                        tmp_ip += ".";
                }
                // 
                res.push_back(std::move(tmp_ip));
            }
            return;
        }
        // 遍历完全部的字符
        if(s_start == s.size()) {
            return;
        }

        // 对0打头的字符特殊处理
        if(s[s_start] == '0') {
            // 0 加入当前结果，继续向下一层回溯
            segments[tmp_size] = 0;
            DFS(s, tmp_size+1, s_start+1);
        }

        // 一般情况, 逐个向后查看
        int num = 0;
        for(int i = s_start; i < s.size(); i++) {
            num = 10*num + (int)(s[i] - '0');
            // 如果数字符合条件就加入segments
            if (num > 0 && num <= 255) {
                segments[tmp_size] = num;
                // 向下一位回溯
                DFS(s, tmp_size+1, i+1);
            } else {
                break;
            }
        }
    }
    std::vector<std::string> restoreIpAddresses(std::string s) {
        segments.resize(4);
        DFS(s, 0, 0);
        return res;
    }
};
// @lc code=end

