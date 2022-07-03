/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 * Date: 2021-04-26
 * method: 二分法
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int maxWeight = 0;
        int sumWeight = 0;
        for(int weight: weights) {
            maxWeight = (weight > maxWeight) ? weight: maxWeight;
            sumWeight += weight;
        }
        int left = maxWeight;
        int right = sumWeight;
        int mid = 0;
        while (left < right) {
            mid = (left + right) >> 1;
            // need为需要运送的天数
            // currWeight为当前天已经运送的重量之和
            int need = 1;
            int currWeight = 0;
            for(int weight: weights) {
                if(currWeight+weight > mid) {
                    need++;
                    currWeight = 0;
                }
                currWeight += weight;
            }
            // 若需要天数 < D,则减小船运输能力
            if (need <= D)
                right = mid;
            // 否则加强船运输能力
            else
                left = mid+1;
        }
        return left;
    }
};
// @lc code=end

