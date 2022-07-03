/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

// @lc code=start
#include<vector>
#include<algorithm>

class Solution {
public:
    // date: 2021-11-16
    // 扫描线(line-sweep)算法
    // 自定义C++比较函数

    bool cmp(std::vector<int>& a, std::vector<int>& b){
        if(a[0] != b[0])
            return a[0] - b[0];
        else
            return a[1]-b[1];
    }
    
    bool isRectangleCover(std::vector<std::vector<int>>& rectangles) {
        int n = rectangles.size();
        std::vector<std::vector<int>> rs(n*2, std::vector<int>(4, 0));
        int idx = 0;
        for(int i = 0; i < n; i++) {
            // 加入两条竖边
            // 1表示左边；-1表示右边
            rs[idx++] = {rectangles[i][0], rectangles[i][1], rectangles[i][3], 1};
            rs[idx++] = {rectangles[i][2], rectangles[i][1], rectangles[i][3], -1};
        }
        // 排序
        sort(rs.begin(), rs.end(), cmp);
        n *= 2;
        // 分别存储相同的横坐标下「左边的线段」和「右边的线段」 (y1, y2)
        std::vector<std::vector<int>> l1;
        std::vector<std::vector<int>> l2;
        // 双指针遍历每一个集合中的横坐标，通过横坐标获取到矩形的纵线段
        int l = 0;
        while(l < n) {
            int r = 1;
            l1.clear();
            l2.clear();
            // 找到横坐标相同部分
            while (r < n && rs[r][0] == rs[l][0]) 
                r++;
            for (int i = l; i < r; i++) {
                //得到当前横坐标上的线段，二元组 [纵坐标起始位置，纵坐标终止位置]
                std::vector<int> curr = {rs[i][1], rs[i][2]};
                //引用传递，line直接指向左线段或者右线段集合
                std::vector<std::vector<int>> list = rs[i][3] == 1 ? l1 : l2;
                if(list.empty()) {
                    list.push_back(curr);
                }
                else {
                    std::vector<int> pre = list[list.size()-1];
                    if(curr[0] < pre[1])
                        return false;
                    else if(curr[0] == pre[1])
                        pre[1] = curr[1];
                    else
                        list.push_back(curr);
                }
            }
            if(l > 0 && r < n) {
                if(l1.size() != l2.size())
                    return false;
                for (int i = 0; i < l1.size(); i++) {
                    if(l1[i][0] == l2[i][0] && l1[i][1] == l2[i][1])
                        continue;
                    return false;
                }
            }
            else {
                if(l1.size() + l2.size() != 1)
                    return false;
            }
            l = r;
        }
        return true;
    }
};
// @lc code=end

